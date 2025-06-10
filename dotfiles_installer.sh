#!/bin/bash

clear
cp -r .config/* -t ~/.config/
cp -r Documents/* -t ~/Documents/
cp -r Pictures/* -t ~/Pictures/
cp -r home/* -t ~/
cp -r home/.zshrc home/.fehbg home/.p10k.zsh home/.xinitrc -t ~/
sudo cp -r ./font/Monocraft* -t /usr/share/fonts/
sudo cp -r ./cursor/* -t /usr/share/icons/
sudo cp -r ./gtkthemes/* -t /usr/share/themes/
cp -r home/.zshrc home/.p10k.zsh -t ~/
sudo chmod -R 777 /usr/share/themes
sudo chmod -R 777 /usr/share/icons
sudo chmod -R 777 /usr/bin/papirus-folders
wal -i '~/Pictures/wallpaper/anon-orange.jpg' &> /dev/null
feh --no-fehbg --bg-scale '~/Pictures/wallpaper/anon-orange.jpg' &> /dev/null
gsettings set org.gnome.desktop.interface icon-theme 'Papirus-Dark' &> /dev/null
gsettings set org.gnome.desktop.interface gtk-theme "dwm-dots" &> /dev/null
gsettings set org.gnome.desktop.interface cursor-theme "dwm-dots" &> /dev/null
papirus-folders -C grey &> /dev/null
clear
echo "*****************************"
echo "Now, we're gonna compile DWM!"
echo "*****************************"
sleep 3
clear
echo "***************************************************************************************"
echo "When it finishes, kill X session by typing "pkill x" and then "startx" to start it again!"
echo "***************************************************************************************"
sleep 5
echo "******************************************************"
echo "Open the wallpaper selector pressing Alt + C!"
echo "Open ST terminal pressing Alt + Enter!"
echo "Open Rofi app menu pressing Alt + X!"
echo "Open Rofi power menu pressing Alt + Z!"
echo "******************************************************"
sleep 8
clear
cd ~/dwm
sudo make clean install
clear
echo "*****************************"
echo "Now, we're gonna compile ST!"
echo "*****************************"
sleep 3
clear
cd ~/st
sudo make clean install

