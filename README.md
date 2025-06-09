# A DWM rice
## Warning
**Clearing the cache and logging out of Hyprland will prevent SWWW from setting the wallpaper automatically. You'll need to reapply your theme using the theme-switcher (ALT+C) or rerun the dotfiles installer.**




## 1. Dependencies installation

**You will have to manually install the dependencies**

#### DWM (optional as it will be installed running the dotfiles_installer.sh)
```
git clone https://git.suckless.org/dwm
cd dwm
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
#### Picom
```
sudo pacman -S picom
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
#### Alacritty: 
```
sudo pacman -S alacritty
```
#### Nerd-fonts and Awesome-fonts: 
```
sudo pacman -S awesome-terminal-fonts otf-font-awesome ttf-font-awesome ttf-jetbrains-mono ttf-jetbrains-mono-nerd 
```
#### Fastfetch: 
```
sudo pacman -S fastfetch imagemagick w3m
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

  <a>https://github.com/adi1090x/rofi</a>

## 2. Dotfiles installation
#### Paste it in your terminal:
```
---
```
## 3. To help you
#### LXappearance: 
```
sudo pacman -S lxappearance
```
#### Apple Keyboard native path to configure key layout: 
```
/sys/bus/hid/drivers/apple/module/parameters
```
#### Keyd for remaping keys at kernel level: 
```
sudo pacman -S keyd
```

