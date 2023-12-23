static const char norm_fg[] = "#e0def4";
static const char norm_bg[] = "#1f1d2e";
static const char norm_border[] = "#1f1d2e";

static const char sel_fg[] = "#191724";
static const char sel_bg[] = "#f6c177";
static const char sel_border[] = "#c4a7e7";


static const char *colors[][3]      = {
    /*               fg           bg         border                         */
    [SchemeNorm] = { norm_fg,     norm_bg,   norm_border }, // unfocused wins
    [SchemeSel]  = { sel_fg,      sel_bg,    sel_border },  // the focused win
};

