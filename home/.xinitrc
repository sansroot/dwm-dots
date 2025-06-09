#!/bin/bash

[ -x "$HOME/.fehbg" ] && "$HOME/.fehbg"
picom &

get_volume() {
  default_sink=$(pactl info | grep 'Default Sink' | awk -F': ' '{print $2}')
  if [ -z "$default_sink" ]; then
    echo "n/a"
    return
  fi

  mute=$(pactl get-sink-mute "$default_sink" | awk '{print $2}')
  if [ "$mute" = "yes" ]; then
    echo "muted"
  else
    pactl get-sink-volume "$default_sink" | grep -o '[0-9]\+%' | head -1
  fi
}

update_bar() {
  dte="$(date +"%A, %B %d - %H:%M")"
  layout=$(setxkbmap -query | awk '/layout:/ {print $2}')
  vol=$(get_volume)

  xsetroot -name " ⌨️ $layout | 🔊 $vol | 🕒 $dte"
}

if [ "$1" == "update_bar" ]; then
  update_bar
  exit 0
fi

while true; do
  update_bar
  sleep 30s
done &

while true; do
  dwm
done
