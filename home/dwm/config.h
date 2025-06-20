/* appearance */
#include <X11/XF86keysym.h>
static const unsigned int borderpx  = 3;        /* border pixel of windows */
static const unsigned int gappx     = 11;        /* gaps between windows */
static const unsigned int snap      = 32;       /* snap pixel */
static const int showbar            = 1;        /* 0 means no bar */
static const int topbar             = 1;        /* 0 means bottom bar */
static const int user_bh            = 10;        /* 2 is the default spacing around the bar's font */
static const char *fonts[]          = {"Monocraft:size=10"};
static const char dmenufont[]       =  "Monocraft:size=10";
static const char norm_fg[] = "";
static const char norm_bg[] = "";
static const char norm_border[] = "";
static const char sel_fg[] = "";
static const char sel_bg[] = "";
static const char sel_border[] = "";
static const char *colors[][3]      = {
    /*               fg           bg         border                         */
    [SchemeNorm] = { norm_fg,     norm_bg,   norm_border }, // unfocused wins
    [SchemeSel]  = { sel_fg,      sel_bg,    sel_border },  // the focused win
};

/* tagging */
static const char *tags[] = {"󰲠", "󰲢", "󰲤", "󰲦", "󰲨"};
static const unsigned int ulinepad	= 0.1;	/* horizontal padding between the underline and tag */
static const unsigned int ulinestroke	= 2;	/* thickness / height of the underline */
static const unsigned int ulinevoffset	= 0;	/* how far above the bottom of the bar the line should appear */
static const int ulineall 		= 0;	/* 1 to show underline on all tags, 0 for just the active ones */
static const Rule rules[] = {
	/* xprop(1):
	 *	WM_CLASS(STRING) = instance, class
	 *	WM_NAME(STRING) = title
	 */
	/* class      instance    title       tags mask     isfloating   monitor */
	{ "Gimp",     NULL,       NULL,       0,            1,           -1 },
	{ "Firefox",  NULL,       NULL,       1 << 8,       0,           -1 },
};

/* layout(s) */
static const float mfact     = 0.55; /* factor of master area size [0.05..0.95] */
static const int nmaster     = 1;    /* number of clients in master area */
static const int resizehints = 1;    /* 1 means respect size hints in tiled resizals */
static const int lockfullscreen = 1; /* 1 will force focus on the fullscreen window */

static const Layout layouts[] = {
	{ "",      tile },    
	{ "",      NULL },    
	{ "",      NULL },
};

/* key definitions */
#define MODKEY Mod1Mask
#define TAGKEYS(KEY,TAG) \
	{ MODKEY,                       KEY,      view,           {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask,           KEY,      toggleview,     {.ui = 1 << TAG} },
#define TAGKEYS_SUPER(KEY,TAG) \
	{ Mod4Mask,                     KEY,      tag,            {.ui = 1 << TAG} }, \
	{ Mod4Mask|ControlMask,         KEY,      toggletag,      {.ui = 1 << TAG} },

/* helper for spawning shell commands in the pre dwm-5.0 fashion */
#define SHCMD(cmd) { .v = (const char*[]){ "/bin/sh", "-c", cmd, NULL } }

/* commands */
static char dmenumon[2] = "0"; /* component of dmenucmd, manipulated in spawn() */
static const char *termcmd[]  = { "st", NULL };
static const char *rofi[] = { "rofi", "-show", "drun", NULL };
static const char *pywal[] = { "bash", "-c", "$HOME/Documents/wallpaper/rofi-wallpaper-selector.sh", NULL };
static const char *powermenu[] = { "bash", "-c", "$HOME/.config/rofi/powermenu.sh", NULL };
static const char *slock[] = { "slock", NULL };
static const char *dmenucmd[] = {
  "dmenu_run", "-m", dmenumon, "-fn", dmenufont,
  "-nb", "#1e1e2e", "-nf", "#cdd6f4",
  "-sb", "#89b4fa", "-sf", "#1e1e2e", NULL
};

static const Key keys[] = {
	/* modifier                     key        function        argument */
	{ MODKEY,                       XK_x,      spawn,          {.v = rofi } },
	{ MODKEY|ShiftMask,             XK_minus,  setgaps,        {.i = -1 } },
	{ Mod4Mask,                     XK_Up,     spawn,          SHCMD("pactl set-sink-volume @DEFAULT_SINK@ +5% && ~/.xinitrc update_bar") },
	{ Mod4Mask,                     XK_Down,   spawn,          SHCMD("pactl set-sink-volume @DEFAULT_SINK@ -5% && ~/.xinitrc update_bar") },
	{ Mod4Mask,                     XK_Left,   spawn,          SHCMD("pactl set-sink-mute @DEFAULT_SINK@ toggle && ~/.xinitrc update_bar") },
	{ Mod4Mask,                     XK_k,      spawn,          SHCMD("killall picom") },
	{ Mod4Mask,             XK_f,      togglefullscr,  {0} },
	{ Mod4Mask,                     XK_j,      spawn,          SHCMD("picom -b") },
	{ MODKEY, XK_e,                            spawn,          SHCMD("thunar") },
	{ MODKEY|ShiftMask,             XK_equal,  setgaps,        {.i = +1 } },
	{ MODKEY|ShiftMask,             XK_0,      setgaps,        {.i = 0  } },
	{ MODKEY,                       XK_c,      spawn,          {.v = pywal } },
	{ MODKEY,                       XK_z,      spawn,          {.v = powermenu } },
	{ Mod4Mask,                     XK_l,      spawn,          {.v = slock } },
	{ MODKEY,                       XK_Return, spawn,          {.v = termcmd } },
	{ MODKEY,                       XK_b,      togglebar,      {0} },
	{ MODKEY,                       XK_a,      focusstack,     {.i = +1 } },
	{ MODKEY,                       XK_d,      focusstack,     {.i = -1 } },
	{ MODKEY,                       XK_i,      incnmaster,     {.i = +1 } },
	//{ MODKEY,                     XK_d,      incnmaster,     {.i = -1 } },
	{ MODKEY,                       XK_h,      setmfact,       {.f = -0.05} },
	{ MODKEY,                       XK_l,      setmfact,       {.f = +0.05} },
	{ MODKEY,                       XK_Return, zoom,           {0} },
	{ MODKEY,                       XK_Tab,    view,           {0} },
	{ MODKEY,                       XK_q,      killclient,     {0} },
	{ MODKEY,                       XK_t,      setlayout,      {.v = &layouts[0]} },
	//{ Mod4Mask,                   XK_f,      setlayout,      {.v = &layouts[1]} },
	//{ MODKEY,                     XK_m,      setlayout,      {.v = &layouts[2]} },
	//{ MODKEY,                     XK_space,  setlayout,      {0} },
	{ MODKEY,                       XK_f,      togglefloating, {0} },
	{ ControlMask,                  XK_space,  spawn,          SHCMD("bash -c 'setxkbmap -query | grep -q \"layout:\\\\s*us\" && setxkbmap br || setxkbmap us; ~/.xinitrc update_bar &'") },
	{ MODKEY,                       XK_0,      view,           {.ui = ~0 } },
	{ MODKEY|ShiftMask,             XK_0,      tag,            {.ui = ~0 } },
	{ MODKEY,                       XK_comma,  focusmon,       {.i = -1 } },
	{ MODKEY,                       XK_period, focusmon,       {.i = +1 } },
	{ MODKEY|ShiftMask,             XK_comma,  tagmon,         {.i = -1 } },
	{ MODKEY|ShiftMask,             XK_period, tagmon,         {.i = +1 } },
	{ Mod4Mask,                     XK_m,      quit,           {0} },
	TAGKEYS(XK_1, 0)
	TAGKEYS(XK_2, 1)
	TAGKEYS(XK_3, 2)
	TAGKEYS(XK_4, 3)
	TAGKEYS(XK_5, 4)
	TAGKEYS(XK_6, 5)
	TAGKEYS(XK_7, 6)
	TAGKEYS(XK_8, 7)
	TAGKEYS(XK_9, 8)
	TAGKEYS_SUPER(XK_1, 0)
	TAGKEYS_SUPER(XK_2, 1)
	TAGKEYS_SUPER(XK_3, 2)
	TAGKEYS_SUPER(XK_4, 3)
	TAGKEYS_SUPER(XK_5, 4)
	TAGKEYS_SUPER(XK_6, 5)
	TAGKEYS_SUPER(XK_7, 6)
	TAGKEYS_SUPER(XK_8, 7)
	TAGKEYS_SUPER(XK_9, 8)
};

/* button definitions */
/* click can be ClkTagBar, ClkLtSymbol, ClkStatusText, ClkWinTitle, ClkClientWin, or ClkRootWin */
static const Button buttons[] = {
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
