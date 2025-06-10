# A DWM rice
## Warning
**Clearing the cache and logging out of Hyprland will prevent SWWW from setting the wallpaper automatically. You'll need to reapply your theme using the theme-switcher (ALT+C) or rerun the dotfiles installer.**




## 1. Dependencies installation

**You will have to manually install the dependencies**

### Wallpapers
#### You can download or place the repo below on your ~/Pictures
<a>https://github.com/sansroot/wallpaper</a>

#### DWM (optional as it will be installed running the dotfiles_installer.sh)
```
git clone https://git.suckless.org/dwm
cd dwm
sudo make clean install
```
#### ST (optional as it will be installed running the dotfiles_installer.sh)
```
git clone https://git.suckless.org/st
cd st
sudo make clean install
```
#### Papirus Icons
```
yay -S papirus-folders-catppuccin-git
```
#### Pywal
```
yay -S pyton-pywal16
```
#### Slock
```
sudo pacman -S Slock
```
#### Picom
```
yay -S picom-pijulius-next-git
```
#### Xorg-xsetroot
```
sudo pacman -S xorg-xsetroot
```
#### Zsh: 
```
sudo pacman -S zsh 
```
#### Feh: 
```
sudo pacman -S feh
```
#### Nerd-fonts and Awesome-fonts: 
```
sudo pacman -S awesome-terminal-fonts otf-font-awesome ttf-font-awesome ttf-jetbrains-mono ttf-jetbrains-mono-nerd 
```
#### Oh-my-ZSH: 

<a>https://github.com/ohmyzsh/ohmyzsh</a>

#### Zsh auto-suggestion and syntax-highlight

<a>https://gist.github.com/n1snt/454b879b8f0b7995740ae04c5fb5b7df</a>

#### PowerLevel10K:

<a>https://github.com/romkatv/powerlevel10k</a>
## Rofi
#### Rofi:
  ```
  sudo pacman -S rofi
  ```
#### Rofi fonts:
```
git clone --depth=1 https://github.com/adi1090x/rofi.git
cd rofi
sudo chmod +x setup.sh
./setup.sh
rm -rf ~/.config/rofi
```
## 2. Dotfiles installation
#### Paste it in your terminal:
```
git clone https://github.com/sansroot/dwm-dots
cd dwm-dots
sudo chmod -R 777 .
./dotfiles_installer.sh
```
## 3. To help you
#### LXappearance: 
```
sudo pacman -S lxappearance
```
#### Nwg-Look: 
```
sudo pacman -S nwg-look
```
#### Apple Keyboard native path to configure key layout: 
```
/sys/bus/hid/drivers/apple/module/parameters
```
#### Keyd for remaping keys at kernel level: 
```
sudo pacman -S keyd
```

