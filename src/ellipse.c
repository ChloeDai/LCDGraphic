#include <stdlib.h>
#include "graphic.h"

void ellipse_fillpixel(int **buffer, int x0, int y0, int x, int y, int color){
	DrawHorzLine(buffer, x0 - x, y0 + y, x<<1, color);
	DrawHorzLine(buffer, x0 - x, y0 - y, x<<1, color);
}

void ellipse_framepixel(int **buffer, int x0, int y0, int x, int y, int color){
    if (x0+x >= 0 && x0+x < WIDTH){
        if (y0+y >= 0 && y0+y < HEIGHT) {buffer[y0+y][x0+x] = color;}
        if (y0-y >= 0 && y0-y < HEIGHT) {buffer[y0-y][x0+x] = color;}
    }
    if (x0-x >= 0 && x0-x < WIDTH){
        if (y0+y >= 0 && y0+y < HEIGHT) {buffer[y0+y][x0-x] = color;}
        if (y0-y >= 0 && y0-y < HEIGHT) {buffer[y0-y][x0-x] = color;}
    }
}

void DrawEllipse(int **buffer, int x0, int y0, int xRadius, int yRadius, int color, bool fill){
    void ((*ellipse_putpixel)(int**, int, int, int, int, int)) = fill?(&ellipse_fillpixel):(&ellipse_framepixel);
	int x = xRadius;
	int y = 0;
	int xRadiusSquare = xRadius*xRadius;
	int yRadiusSquare = yRadius*yRadius;
	int dx = yRadiusSquare*(1-(xRadius<<1));
	int dy = xRadiusSquare;
	int err = 0;
	int xRadiusSquareX2 = xRadiusSquare<<1;
	int yRadiusSquareX2 = yRadiusSquare<<1;
	int endX = yRadiusSquareX2*xRadius;
	int endY = 0;

	while (endX >= endY){ //first set of points,y'>-1
		ellipse_putpixel(buffer, x0, y0, x, y, color);
		y++;
		endY += xRadiusSquareX2;
		err = err + dy;
		dy += xRadiusSquareX2;
		if(((err<<1)+dx)>0){
			x--;
			endX -= yRadiusSquareX2;
			err += dx;
			dx += yRadiusSquareX2;
		}
	}
	//{ first point set is done; start the 2nd set of points }

	y = yRadius;
	x = 0;
	dy = xRadiusSquare*(1-(yRadius<<1));
	dx = yRadiusSquare;
	err = 0;
	endY = xRadiusSquareX2*yRadius;
	endX = 0;
	while (endY >= endX){ //{2nd set of points, y'< -1}
		ellipse_putpixel(buffer, x0, y0, x, y, color);
		x++;
		endX += yRadiusSquareX2;
		err += dx;
		dx += yRadiusSquareX2;
		if(((err<<1)+dy)>0){
			y--;
			endY -= xRadiusSquareX2;
			err += dy;
			dy += xRadiusSquareX2;
		}
	}
}