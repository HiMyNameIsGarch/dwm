//Modify this file to change what commands output to your statusbar, and recompile using the make command.
static const Block blocks[] = {
	/*Icon*/	/*Command*/		/*Update Interval*/	/*Update Signal*/
    {"",        "updates",         3600,            0}, 
    {"",        "disk-space",      240,             0},
    {"",        "mem-usage",       3,		        0},
    {"",        "gpu-temp",        3,               0}, 
    {"",        "cpu-temp",        3,               0}, 
    {"",        "cpu-usage",       3,               0}, 
	{"",        "bar-date ",       60,		        0},
};

//sets delimeter between status commands. NULL character ('\0') means no delimeter.
static char delim[] = " | ";
static unsigned int delimLen = 5;
