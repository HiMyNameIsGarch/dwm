/* See LICENSE file for copyright and license details. */

/* appearance */
static const unsigned int borderpx  = 3;        /* border pixel of windows */
static const unsigned int gappx     = 0;        /* gaps between windows */
static const unsigned int snap      = 32;       /* snap pixel */
static const int showbar            = 1;        /* 0 means no bar */
static const int topbar             = 1;        /* 0 means bottom bar */
static const int user_bh = 23; /* 0 means that dwm will calculate bar height, >= 1 means dwm will user_bh as bar height */
static const char *fonts[]          = { "UbuntuMono Nerd Font:size=13" };
static const char dmenufont[]       = "monospace:size=10";

static const char norm_fg[] = "#fbf1c7";
static const char norm_bg[] = "#282828";
static const char norm_border[] = "#282828";

static const char sel_fg[] = "#ebdbb2";
static const char sel_bg[] = "#d65d0e";
static const char sel_border[] = "#d5c4a1";


static const char *colors[][3]      = {
    /*               fg           bg         border                         */
    [SchemeNorm] = { norm_fg,     norm_bg,   norm_border }, // unfocused wins
    [SchemeSel]  = { sel_fg,      sel_bg,    sel_border },  // the focused win
};

/* tagging */
static const char *tags[] = { "web", "dev", "sys", "git", "cht", "vid", "doc", "box", "mus" };

static const Rule rules[] = {
	/* xprop(1):
	 *	WM_CLASS(STRING) = instance, class
	 *	WM_NAME(STRING) = title
	 */
	/* class      instance    title       tags mask     isfloating   monitor */
	{ "Gimp",     NULL,       NULL,       0,            1,           -1 },
	{ "Gimp",     NULL,       NULL,       0,            1,           -1 }
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
static const char *termcmd[] = { "alacritty", NULL };

/* bindings */
static Key keys[] = {
	/* modifier                     key        function        argument */

    /* Programs */
	{ MODKEY|ShiftMask,             XK_b,      spawn,          SHCMD("qutebrowser") },
	{ MODKEY|ShiftMask,             XK_l,      spawn,          SHCMD("librewolf") },
	/*{ MODKEY|ShiftMask,             XK_f,      spawn,          SHCMD("firefox") },*/
    /* Scripts */
    { ALTKEY,                       XK_l,      spawn,          SHCMD("i3lock -i /home/himynameisgarch/Media/Wallpapers/Simple/GruvTown.png") },
    { ALTKEY,                       XK_s,      spawn,          SHCMD("process") },
    { MODKEY|ShiftMask,             XK_m,      spawn,          SHCMD("mdisk") },
    { MODKEY|ShiftMask,             XK_c,      spawn,          SHCMD("confs") },
    { MODKEY|ShiftMask,             XK_t,      spawn,          SHCMD("todo")  },
    { MODKEY|ShiftMask,             XK_p,      spawn,          SHCMD("passmenu") },
    { MODKEY|ShiftMask,             XK_s,      spawn,          SHCMD("gscreenshot -sc") },
    { MODKEY,                       XK_s,      spawn,          SHCMD("gscreenshot -c") },
    { MODKEY,                       XK_w,      spawn,          SHCMD("mstat") },
    { MODKEY,                       XK_p,      spawn,          SHCMD("dmenu-recent") },
    /* Cmus */
    { MODKEY,                       XK_F2,     spawn,          SHCMD("cmus-remote --volume -5%") },
    { MODKEY,                       XK_F3,     spawn,          SHCMD("cmus-remote --volume +5%") },
    { 0,                            XK_F5,     spawn,          SHCMD("cmus-remote --stop") },
    { 0,                            XK_F6,     spawn,          SHCMD("cmus-remote --prev") },
    { 0,                            XK_F7,     spawn,          SHCMD("cmus-pp") },
    { 0,                            XK_F8,     spawn,          SHCMD("cmus-remote --next") },
    /* Audio */
    { 0,                            XK_F2,     spawn,          SHCMD("vol down") },
    { 0,                            XK_F3,     spawn,          SHCMD("vol up") },
    { MODKEY,                       XK_F1,     spawn,          SHCMD("vol toggle") },
    { 0,                            XK_F1,     spawn,          SHCMD("audio 1") },
    { MODKEY,                       XK_F4,     spawn,          SHCMD("vol mute") },
    { 0,                            XK_F4,     spawn,          SHCMD("audio 0") },
    /* System */
	{ MODKEY,                       XK_Return, spawn,          {.v = termcmd } },
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
	{ MODKEY,                       XK_minus,  setgaps,        {.i = -5 } },
	{ MODKEY,                       XK_equal,  setgaps,        {.i = +5 } },
	{ MODKEY|ShiftMask,             XK_equal,  setgaps,        {.i = 0  } },
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

