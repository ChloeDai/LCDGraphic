#include <stdbool.h>

#define WIDTH 320
#define HEIGHT 200

#define PI 					3.1415926535897932384626433832795
#define ARC_A				0.0776509570923569
#define ARC_B				-0.287434475393028
#define ARC_C				((PI/4)-ARC_A-ARC_B)

void DrawHorzLine(int** buffer, int x0, int y, int width, int color);
void DrawVertLine(int** buffer, int x, int y0, int height, int color);
void DrawLine(int** buffer, int x0, int y0, int x1, int y1, int color);

void DrawRectangle(int** buffer, int x, int y, int width, int height, int color, bool fill);
void DrawRoundedRectangle(int** buffer, int x, int y, int width, int height, int radius, int color, bool fill);

void DrawTriangle(int** buffer, int x0, int y0, int x1, int y1, int x2, int y2, int color, bool fill);

void DrawCircle(int **buffer, int x0, int y0, int r, int color, bool fill);

void arc_putpixel(int **buffer, int x0, int y0, int color);
void DrawArc(int **buffer, int x0, int y0, int r, int thick, int start_angle, int end_angle, int color);

void sector_putpixel(int **buffer, int x0, int y0, int x1, int y1, int color);
void DrawSector(int **buffer, int x0, int y0, int r, int s, int e, int color);

void ellipse_fillpixel(int **buffer, int x0, int y0, int x, int y, int color);
void ellipse_framepixel(int **buffer, int x0, int y0, int x, int y, int color);
void DrawEllipse(int **buffer, int x0, int y0, int xRadius, int yRadius, int color, bool fill);