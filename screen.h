
enum FGCOLOR {BLACK=30, RED, GREEN, YELLOW, BLUE, MAGENTA, CYAN, WHITE};
#define bg(a) (a+10)
#define BAR "\u2590"
// function prototype
void clearScreen(void);
void gotoxy(short x, short y);
void setColors(short bg, short fg);
void resetColors(void);
void setXYColor(short x, short y, short fg, short bg);
void displayBar(short x,short y,short bottom);
