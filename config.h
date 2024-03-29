/* See LICENSE file for copyright and license details. */

/* appearance */
static const unsigned int borderpx  = 3;        /* border pixel of windows */
static const unsigned int snap      = 32;       /* snap pixel */
static const int showbar            = 1;        /* 0 means no bar */
static const int topbar             = 1;        /* 0 means bottom bar */
static const int user_bh = 22; /* 0 means that dwm will calculate bar height, >= 1 means dwm will user_bh as bar height */
static const char *fonts[]          = { "UbuntuMono Nerd Font:size=12" };
static const char dmenufont[]       = "monospace:size=10";

#include "colors.h"

/* tagging */
static const char *tags[] = { "web", "dev", "sys", "zed", "cht", "nul", "box", "tor", "mus" };

static const Rule rules[] = {
	/* xprop(1):
	 *	WM_CLASS(STRING) = instance, class
	 *	WM_NAME(STRING) = title
	 */
	/* class                    instance    title    tags mask   isfloating   monitor */
    { "qutebrowser",            NULL,       NULL,    1 << 0,     0,           -1 },
    { "LibreWolf",              NULL,       NULL,    1 << 2,     0,           -1 },
    { "firefox",                NULL,       NULL,    1 << 3,     0,           -1 },
    { "Element",                NULL,       NULL,    1 << 4,     0,           -1 },
    { "Virt-manager",           NULL,       NULL,    1 << 6,     0,           -1 },
	{ "qBittorrent",            NULL,       NULL,    1 << 7,     0,           -1 },
	{ "Spotify",                NULL,       NULL,    1 << 8,     0,           -1 },
};

/* layout(s) */
static const float mfact     = 0.55; /* factor of master area size [0.05..0.95] */
static const int nmaster     = 1;    /* number of clients in master area */
static const int resizehints = 1;    /* 1 means respect size hints in tiled resizals */

static const Layout layouts[] = {
	/* symbol     arrange function */
	{ "[]=",      tile },    /* first entry is default */
	{ "><>",      NULL },    /* no layout function means floating behavior */
	{ "[M]",      monocle },
};

/* key definitions */
#define MODKEY Mod4Mask
#define ALTKEY Mod1Mask
#define TAGKEYS(KEY,TAG) \
	{ MODKEY,                       KEY,      view,           {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask,           KEY,      toggleview,     {.ui = 1 << TAG} }, \
	{ MODKEY|ShiftMask,             KEY,      tag,            {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask|ShiftMask, KEY,      toggletag,      {.ui = 1 << TAG} },

/* helper for spawning shell commands in the pre dwm-5.0 fashion */
#define SHCMD(cmd) { .v = (const char*[]){ "/bin/sh", "-c", cmd, NULL } }

/* commands */
static char dmenumon[2] = "0"; /* component of dmenucmd, manipulated in spawn() */
static const char *dmenucmd[] = { "dmenu-recent", NULL };
// new_ttmux is a custom script found in .local/bin/
static const char *termdmenucmd[] = { "alacritty", "-e","new_ttmux", "dmenu", NULL };
static const char *termcmd[] = { "alacritty", "-e", "new_ttmux", NULL };
static const char *qutebcmd[] = { "qutebrowser", NULL };
static const char *wolfcmd[] = { "librewolf", NULL };
static const char *sitecmd[] = { "sites", NULL };
static const char *gumball[] = { "gumball", NULL };

#include <X11/XF86keysym.h>

/* bindings */
static Key keys[] = {
	/* modifier                     key        function        argument */

    /* I know audio key to change a wallpaper, my thought: useless key in a good position */
    // { 0,                  XF86XK_AudioStop,    spawn,          SHCMD("feh --no-fehbg --bg-scale --randomize --recursive /home/garch/Media/Wallpapers") },

    /* Programs */
	{ MODKEY|ShiftMask,             XK_b,      spawn,          {.v = qutebcmd } },
	{ MODKEY|ShiftMask,             XK_l,      spawn,          {.v = wolfcmd  } },
	/*{ MODKEY|ShiftMask,             XK_f,      spawn,          SHCMD("firefox") },*/
    /* Scripts */
    { 0,                            XK_Pause,  spawn,          SHCMD("i3lock -i /home/garch/Media/Wallpapers/Simple/GruvTown.png") },
    { ALTKEY,                       XK_s,      spawn,          SHCMD("process") },
    { MODKEY|ShiftMask,             XK_m,      spawn,          SHCMD("mdisk") },
    { MODKEY|ShiftMask,             XK_c,      spawn,          SHCMD("confs menu") },
    { MODKEY|ShiftMask,             XK_t,      spawn,          SHCMD("todo")  },
    { MODKEY|ShiftMask,             XK_p,      spawn,          SHCMD("passmenu") },
    { MODKEY,                       XK_Print,  spawn,          SHCMD("screenshot") },
    { 0,                            XK_Print,  spawn,          SHCMD("screenshot a") },
    { MODKEY,                       XK_w,      spawn,          SHCMD("mstat") },
    { MODKEY,                       XK_p,      spawn,          SHCMD("dmenu-recent") },
    { MODKEY,                       XK_e,      spawn,          SHCMD("lyrics") },
    { MODKEY,                       XK_u,      spawn,          {.v = sitecmd } },
    { MODKEY,                       XK_F4,     spawn,          {.v = gumball } },
    /* Cmus */
    { 0,            XF86XK_AudioPlay,          spawn,          SHCMD("playerctl play-pause") },
    { 0,            XF86XK_AudioStop,          spawn,          SHCMD("playerctl stop") },
    { 0,            XF86XK_AudioPrev,          spawn,          SHCMD("playerctl previous") },
    { 0,            XF86XK_AudioNext,          spawn,          SHCMD("playerctl next") },
    /* Audio */
    { 0,                            XK_F2,     spawn,          SHCMD("vol down") },
    { 0,                            XK_F3,     spawn,          SHCMD("vol up") },
    // Brightness
    { 0,                            XK_F5,     spawn,          SHCMD("shedlight d") },
    { 0,                            XK_F6,     spawn,          SHCMD("shedlight u") },
    // Invert screen hahaha
    { 0,                            XK_F7,     spawn,          SHCMD("rotate_screen") },
    // Bluetooth easy connect
    { 0,                            XK_F12,    spawn,          SHCMD("blth") },
    // ytfzf with actually dmenu ( kinda )
    { 0,                            XK_F9,     spawn,          SHCMD("ytpls") },
    /* System */
	{ MODKEY,                       XK_Return, spawn,          {.v = termcmd } },
	{ MODKEY|ShiftMask,             XK_Return, spawn,          {.v = termdmenucmd } },
	{ MODKEY,                       XK_b,      togglebar,      {0} },
	{ MODKEY,                       XK_j,      focusstack,     {.i = +1 } },
	{ MODKEY,                       XK_k,      focusstack,     {.i = -1 } },
	{ MODKEY,                       XK_i,      incnmaster,     {.i = +1 } },
	{ MODKEY,                       XK_d,      incnmaster,     {.i = -1 } },
	{ MODKEY,                       XK_h,      setmfact,       {.f = -0.05} },
	{ MODKEY,                       XK_l,      setmfact,       {.f = +0.05} },
	{ MODKEY|ShiftMask,             XK_Return, zoom,           {0} },
	{ MODKEY,                       XK_Tab,    view,           {0} },
	{ MODKEY,                       XK_q,      killclient,     {0} },
	{ MODKEY,                       XK_t,      setlayout,      {.v = &layouts[0]} },
	{ MODKEY,                       XK_f,      setlayout,      {.v = &layouts[1]} },
	{ MODKEY,                       XK_m,      setlayout,      {.v = &layouts[2]} },
	{ MODKEY,                       XK_space,  setlayout,      {0} },
	{ MODKEY|ShiftMask,             XK_space,  togglefloating, {0} },
	{ MODKEY|ShiftMask,             XK_f,      togglefullscr,  {0} },
	{ MODKEY,                       XK_0,      view,           {.ui = ~0 } },
	{ MODKEY|ShiftMask,             XK_0,      tag,            {.ui = ~0 } },
	{ MODKEY,                       XK_comma,  focusmon,       {.i = -1 } },
	{ MODKEY,                       XK_period, focusmon,       {.i = +1 } },
	{ MODKEY|ShiftMask,             XK_comma,  tagmon,         {.i = -1 } },
	{ MODKEY|ShiftMask,             XK_period, tagmon,         {.i = +1 } },
    /* Workspaces */
	TAGKEYS(                        XK_1,                      0)
	TAGKEYS(                        XK_2,                      1)
	TAGKEYS(                        XK_3,                      2)
	TAGKEYS(                        XK_4,                      3)
    TAGKEYS(                        XK_5,                      4)
	TAGKEYS(                        XK_6,                      5)
	TAGKEYS(                        XK_7,                      6)
	TAGKEYS(                        XK_8,                      7)
	TAGKEYS(                        XK_9,                      8)
	{ MODKEY|ShiftMask,             XK_q,      quit,           {0} },
};

/* button definitions */
/* click can be ClkTagBar, ClkLtSymbol, ClkStatusText, ClkWinTitle, ClkClientWin, or ClkRootWin */
static Button buttons[] = {
	/* click                event mask      button          function        argument */
	{ ClkLtSymbol,          0,              Button1,        setlayout,      {0} },
	{ ClkLtSymbol,          0,              Button3,        setlayout,      {.v = &layouts[2]} },
	{ ClkWinTitle,          0,              Button2,        zoom,           {0} },
	{ ClkStatusText,        0,              Button2,        spawn,          {.v = termcmd } },
	{ ClkClientWin,         MODKEY,         Button1,        movemouse,      {0} },
	{ ClkClientWin,         MODKEY,         Button2,        togglefloating, {0} },
	{ ClkClientWin,         MODKEY,         Button3,        resizemouse,    {0} },
	{ ClkTagBar,            0,              Button1,        view,           {0} },
	{ ClkTagBar,            0,              Button3,        toggleview,     {0} },
	{ ClkTagBar,            MODKEY,         Button1,        tag,            {0} },
	{ ClkTagBar,            MODKEY,         Button3,        toggletag,      {0} },
};
