#include "graphic.h"

void DrawHorzLine(int** buffer, int x0, int y, int width, int color){
	if (y < 0 || y >= HEIGHT) {return;}
	if (width < 0) {
		width = -width;
		x0 -= (width - 1);
	}

	int x1 = x0 + width - 1;
	if (x0 < 0)         {x0 = 0;}
	if (x1 >= WIDTH)    {x1 = WIDTH - 1;}

    for(int x=x0;x<=x1;x++){
        buffer[y][x] = color;
    }
}

void DrawVertLine(int** buffer, int x, int y0, int height, int color){
	if (x < 0 || x >= HEIGHT) {return;}
	if (height < 0) {
		height = -height;
		y0 -= (height - 1);
	}

	int y1 = y0 + height - 1;
	if (y0 < 0)         {y0 = 0;}
	if (y1 >= HEIGHT)   {y1 = HEIGHT - 1;}

    for(int y=y0;y<=y1;y++){
        buffer[y][x] = color;
    }
}

void DrawLine(int** buffer, int x0, int y0, int x1, int y1, int color){
	int dx = x1 - x0;
	int dy = y1 - y0;
	if(dx == 0){
		DrawVertLine(buffer, x0, y0, dy, color);
		return;
	}
	else if(dy == 0){
		DrawHorzLine(buffer, x0, y0, dx, color);
		return;
	}	
	
	int dx_sign = (dx > 0)?1:(-1);
	int dy_sign = (dy > 0)?1:(-1);
	
	dx = dx_sign * dx;
	dy = dy_sign * dy;	
	int dx_x2 = dx<<1;
	int dy_x2 = dy<<1;

	if (dx >= dy) {
	    for(int di=dy_x2-dx;x0!=x1;di+=dy_x2,x0+=dx_sign){
	        if (x0 >= 0 && y0 >= 0 && x0 < WIDTH && y0 < HEIGHT) {
		        buffer[y0][x0] = color;
	        }
			if (di >= 0) {
				di -= dx_x2;
				y0 += dy_sign;
			}
		}
	}
	else {
	    for(int di=dx_x2-dy;y0!=y1;di+=dx_x2,y0+=dy_sign){
	        if (x0 >= 0 && y0 >= 0 && x0 < WIDTH && y0 < HEIGHT) {
		        buffer[y0][x0] = color;
	        }
			if (di >= 0) {
				di -= dy_x2;
				x0 += dx_sign;
			}
		}
	}
}