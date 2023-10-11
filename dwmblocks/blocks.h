//Modify this file to change what commands output to your statusbar, and recompile using the make command.
static const Block blocks[] = {
	/*Icon*/	/*Command*/		/*Update Interval*/	/*Update Signal*/
    {"",        "updates",         3600,            3},
    {"",        "battery",         2,               4},
    {"",        "disk-space",      240,             5},
    {"",        "mem-usage",       3,		        8},
    {"",        "gpu-temp",        3,               20},
    {"",        "power",           2,               21},
	{"",        "bar-date ",       30,		        55},
};

//sets delimeter between status commands. NULL character ('\0') means no delimeter.
static char delim[] = " │ ";
static unsigned int delimLen = 5;
