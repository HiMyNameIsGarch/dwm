# Garch's build of dwm
dwm is an extremely fast, small, and dynamic window manager for X.

If you want to see my scripts that I used in some of the bindings, check out [this](https://github.com/HiMyNameIsGarch/dotfiles/tree/main/.local/bin).
## Bar
I use dwmblocks as my bar and you can found it in this repo. \
The scripts for dwmblocks can be found [here](https://github.com/HiMyNameIsGarch/dotfiles/tree/main/.local/bin/dwm-bar/)
## Patches
 - [Actual fullscreen](https://dwm.suckless.org/patches/actualfullscreen/) - Toggle fullscreen for a window.
 - [Autostart](https://dwm.suckless.org/patches/autostart/) - Start some programs when dwm starts.
 - [Bar height](https://dwm.suckless.org/patches/bar_height/) - Change default value for bar height.
 - [No border](https://dwm.suckless.org/patches/noborder/) - When a single window is visible, do not show the border.
 - [Pertag](https://dwm.suckless.org/patches/pertag/) - Keep some values per tag.
 - [Warp](https://dwm.suckless.org/patches/warp/) - When switching a window, put the cursor in the middle of it.
## Installation
```
git clone https://github.com/HiMyNameIsGarch/dwm
cd dwm
sudo make clean install
```
## Bindings
| Key | Function | Argument |
| :-: | :-: | :- |
| Super + Shift + b | spawns |  qutebrowser  |
| Super + Shift + l | spawns |  librewolf  |
| F12 | spawns | feh --no-fehbg --bg-scale --randomize --recursive /home/himynameisgarch/Media/Wallpapers |
| F11 | spawns | i3lock -i /home/himynameisgarch/Media/Wallpapers/Simple/GruvTown.png |
| Alt + s | spawns | process |
| Super + Shift + m | spawns | mdisk |
| Super + Shift + c | spawns | confs |
| Super + Shift + t | spawns | todo |
| Super + Shift + p | spawns | passmenu |
| Super + Print | spawns | gscreenshot -sc |
| Print | spawns | gscreenshot -c |
| Super + w | spawns | mstat |
| Super + p | spawns | dmenu-recent |
| Super + e | spawns | lyrics |
| Super + u | spawns |  sites  |
| AudioLowerVolume | spawns | cmus-remote --volume -5% |
| AudioRaiseVolume | spawns | cmus-remote --volume +5% |
| AudioStop | spawns | cmus-remote --stop |
| AudioPrev | spawns | cmus-remote --prev |
| AudioPlay | spawns | cmus-pp |
| AudioNext | spawns | cmus-remote --next |
| F2 | spawns | vol down |
| F3 | spawns | vol up |
| Super + F1 | spawns | vol toggle |
| F1 | spawns | audio 1 |
| Super + F4 | spawns | vol mute |
| F4 | spawns | audio 0 |
| Super + Return | spawns |  alacritty  |
| Super + b | togglebar |   |
| Super + j | focusstack |  +1 |
| Super + k | focusstack |  -1 |
| Super + i | incnmaster |  +1 |
| Super + d | incnmaster |  -1 |
| Super + h | setmfact |  -0.05 |
| Super + l | setmfact |  +0.05 |
| Super + Shift + Return | zoom |   |
| Super + Tab | view |   |
| Super + q | killclient |   |
| Super + t | setlayout |  tile  |
| Super + f | setlayout |  float |
| Super + m | setlayout |  monocle  |
| Super + space | setlayout |   |
| Super + Shift + space | togglefloating |   |
| Super + Shift + f | togglefullscr |   |
| Super + 0 | view |  ~0 |
| Super + Shift + 0 | tag |  ~0 |
| Super + comma | focusmon |  -1 |
| Super + period | focusmon |  +1 |
| Super + Shift + comma | tagmon |  -1 |
| Super + Shift + period | tagmon |  +1 |
| Super + Shift + q | quit |   |

If you want the same output over your config, you can use my [script](https://github.com/HiMyNameIsGarch/dotfiles/blob/main/.local/bin/rice).
