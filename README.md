# Garch's build of dwm
dwm is an extremely fast, small, and dynamic window manager for X.

If you want to see my scripts that I used in some of the bindings, check out [this](https://github.com/HiMyNameIsGarch/dotfiles/tree/main/.local/bin).
## Bar
I use dwmblocks as my bar and you can find it [here](https://github.com/HiMyNameIsGarch/dwmblocks).
## Patches
 - [Actual fullscreen](https://dwm.suckless.org/patches/actualfullscreen/) - Toggle fullscreen for a window.
 - [Autostart](https://dwm.suckless.org/patches/autostart/) - Start some programs when dwm starts.
 - [Bar height](https://dwm.suckless.org/patches/bar_height/) - Change default value for bar height.
 - [Fullgaps](https://dwm.suckless.org/patches/fullgaps/) - Add gaps between windows.
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
| Modkey + Shift + b | spawns | qutebrowser |
| Modkey + Shift + l | spawns | librewolf |
| F11 | spawns | i3lock -i /home/himynameisgarch/Media/Wallpapers/Simple/GruvTown.png |
| Alt + s | spawns | process |
| Modkey + Shift + m | spawns | mdisk |
| Modkey + Shift + c | spawns | confs |
| Modkey + Shift + t | spawns | todo |
| Modkey + Shift + p | spawns | passmenu |
| Modkey + Print | spawns | gscreenshot -sc |
| Print | spawns | gscreenshot -c |
| Modkey + w | spawns | mstat |
| Modkey + p | spawns | dmenu-recent |
| Modkey + F2 | spawns | cmus-remote --volume -5% |
| Modkey + F3 | spawns | cmus-remote --volume +5% |
| F5 | spawns | cmus-remote --stop |
| F6 | spawns | cmus-remote --prev |
| F7 | spawns | cmus-pp |
| F8 | spawns | cmus-remote --next |
| F2 | spawns | vol down |
| F3 | spawns | vol up |
| Modkey + F1 | spawns | vol toggle |
| F1 | spawns | audio 1 |
| Modkey + F4 | spawns | vol mute |
| F4 | spawns | audio 0 |
| Modkey + Return | spawns |  alacritty  |
| Modkey + b | togglebar |   |
| Modkey + j | focusstack |  +1 |
| Modkey + k | focusstack |  -1 |
| Modkey + i | incnmaster |  +1 |
| Modkey + d | incnmaster |  -1 |
| Modkey + h | setmfact |  -0.05 |
| Modkey + l | setmfact |  +0.05 |
| Modkey + Shift + Return | zoom |   |
| Modkey + Tab | view |   |
| Modkey + q | killclient |   |
| Modkey + t | setlayout |  tile  |
| Modkey + f | setlayout |  float |
| Modkey + m | setlayout |  monocle  |
| Modkey + space | setlayout |   |
| Modkey + Shift + space | togglefloating |   |
| Modkey + Shift + f | togglefullscr |   |
| Modkey + 0 | view |  0 |
| Modkey + Shift + 0 | tag |  0 |
| Modkey + comma | focusmon |  -1 |
| Modkey + period | focusmon |  +1 |
| Modkey + Shift + comma | tagmon |  -1 |
| Modkey + Shift + period | tagmon |  +1 |
| Modkey + minus | setgaps |  -5 |
| Modkey + equal | setgaps |  +5 |
| Modkey + Shift + equal | setgaps |  0 |
| Modkey + Shift + q | quit |   |
| Key | Function | Argument |

If you want the same output over your config, you can use my [script](https://github.com/HiMyNameIsGarch/dotfiles/blob/main/.local/bin/rice).
