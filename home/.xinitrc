#!/bin/bash

[ -x "$HOME/.fehbg" ] && "$HOME/.fehbg"
picom &
dte() {
  dte="$(date +"%A, %B %d - %H:%M")"
  echo -e "🕒 $dte"
}

upd() {
  upd=$(checkupdates | wc -l)
  echo -e "📦 $upd updates"
}

mem() {
  mem=$(free | awk '/Mem/ {printf "%d MiB/%d MiB\n", $3 / 1024.0, $2 / 1024.0 }')
  echo -e "🧠 $mem"
}

cpu() {
  read cpu a b c previdle rest </proc/stat
  prevtotal=$((a + b + c + previdle))
  sleep 0.5
  read cpu a b c idle rest </proc/stat
  total=$((a + b + c + idle))
  cpu=$((100 * ((total - prevtotal) - (idle - previdle)) / (total - prevtotal)))
  echo -e "🔥 ${cpu}% cpu"
}

layout() {
  layout=$(setxkbmap -query | awk '/layout:/ {print $2}')
  echo -e "⌨️  $layout"
}

while true; do
  xsetroot -name " $(layout) | $(cpu) | $(mem) | $(upd) | $(dte)"
  sleep 5
done &

while true; do
  dwm
done
