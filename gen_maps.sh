#!/bin/bash
# Génère les maps de test cub3D (à lancer depuis la racine du projet)
set -e
mkdir -p textures map/valid map/invalid map/validate
for d in north south west east; do touch "textures/$d.xpm"; done

T='NO ./textures/north.xpm
SO ./textures/south.xpm
WE ./textures/west.xpm
EA ./textures/east.xpm'
FL='F 220,100,0'
CE='C 225,30,0'
ROOM='111111
100001
10N001
100001
111111'

mk() { printf '%s\n' "$2" > "$1"; }

# ===== VALIDES (doivent passer) =====
mk map/valid/simple.cub "$T
$FL
$CE

$ROOM"

mk map/valid/spaces_order.cub "

   C 225 , 30 , 0
NO    ./textures/north.xpm

  F 220,100,0
SO ./textures/south.xpm
EA ./textures/east.xpm


WE ./textures/west.xpm



$ROOM


"

mk map/valid/irregular.cub "$T
$FL
$CE

        1111111
        1000001
111111111000001
100000000000001
1000W0001111111
11111111"

# ===== INVALIDES : arguments / fichier =====
cp map/valid/simple.cub map/invalid/map.txt
cp map/valid/simple.cub map/invalid/.cub
: > map/invalid/empty.cub

# ===== INVALIDES : éléments =====
mk map/invalid/missing_C.cub "$T
$FL

$ROOM"

mk map/invalid/dup_NO.cub "$T
NO ./textures/north.xpm
$FL
$CE

$ROOM"

mk map/invalid/unknown_id.cub "$T
XX ./textures/north.xpm
$FL
$CE

$ROOM"

mk map/invalid/bad_texture_path.cub "NO ./textures/nope.xpm
SO ./textures/south.xpm
WE ./textures/west.xpm
EA ./textures/east.xpm
$FL
$CE

$ROOM"

# ===== INVALIDES : couleurs =====
i=0
for c in "256,100,0" "220,100" "220,100,0," "220,,0" "a,b,c" "-1,100,0" "2 20,100,0" "" "1000,0,0"; do
	i=$((i + 1))
	mk "map/invalid/color_$i.cub" "$T
F $c
$CE

$ROOM"
done

# ===== INVALIDES : map =====
mk map/invalid/no_map.cub "$T
$FL
$CE
"

mk map/invalid/empty_line_in_map.cub "$T
$FL
$CE

111111
100001

10N001
100001
111111"

# ===== INVALIDES pour validate_map (passent le parsing actuel) =====
mk map/validate/open_wall.cub "$T
$FL
$CE

111111
100001
10N000
100001
111111"

mk map/validate/space_hole.cub "$T
$FL
$CE

111111
100001
10N 01
100001
111111"

mk map/validate/two_players.cub "$T
$FL
$CE

111111
10S001
10N001
100001
111111"

mk map/validate/no_player.cub "$T
$FL
$CE

111111
100001
100001
111111"

mk map/validate/bad_char.cub "$T
$FL
$CE

111111
100X01
10N001
111111"

echo "Maps générées : $(find map/valid map/invalid map/validate -type f | wc -l)"