#!/bin/bash
[ -x "$HOME/.fehbg" ] && "$HOME/.fehbg"

# loop do relógio em segundo plano
while true; do
  xsetroot -name "$(date)"
  sleep 1s
done &

# inicia o dwm em loop principal
while true; do
  dwm
done
