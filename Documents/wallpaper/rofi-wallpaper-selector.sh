#!/bin/bash

WALLPAPER_DIR="$HOME/Pictures/wallpaper"

SELECTED=$(for a in "$WALLPAPER_DIR"/*.jpg; do
  echo -en "$(basename "$a")\0icon\x1f$a\n"
done | rofi -dmenu -theme ~/Documents/wallpaper/wallpaper-picker.rasi -p "Escolha o wallpaper")

[ -z "$SELECTED" ] && exit 0

WALLPAPER_PATH="$WALLPAPER_DIR/$SELECTED"

wal -i "$WALLPAPER_PATH"

feh --bg-scale "$WALLPAPER_PATH"

echo "feh --bg-scale" $WALLPAPER_PATH >~/.fehbg

echo "wal -i" $WALLPAPER_PATH >>~/.fehbg

killall dwm




