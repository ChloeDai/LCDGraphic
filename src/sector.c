#include <stdlib.h>
#include "graphic.h"

void sector_putpixel(int **buffer, int x0, int y0, int x1, int y1, int color){
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
	
	int dx_sym = dx > 0 ? 1 : -1;
	int dy_sym = dy > 0 ? 1 : -1;

	dx *= dx_sym;
	dy *= dy_sym;

	int dx_x2 = dx<<1;
	int dy_x2 = dy<<1;

	if (dx >= dy) {
		int di = dy_x2 - dx;
		while (x0 != x1) {
			arc_putpixel(buffer, x0, y0, color);
			x0 += dx_sym;
			if (di < 0) {
				di += dy_x2;
			}
			else {
				di += dy_x2 - dx_x2;
				y0 += dy_sym;
			}
		}
	}
	else {
		int di = dx_x2 - dy;
		while (y0 != y1) {
			arc_putpixel(buffer, x0, y0, color);
			y0 += dy_sym;
			if (di < 0) {
				di += dx_x2;
			}
			else {
				di += dx_x2 - dy_x2;
				x0 += dx_sym;
			}
		}
	}
	arc_putpixel(buffer, x0, y0, color);
}

void DrawSector(int **buffer, int x0, int y0, int r, int s, int e, int color){
	if(e>360 && s>360)		{s = s%360;e = e%360;}
    if(e<=s || r<4) 		{return;}
    else if((e - s) >= 360)	{s = 0;	e = 360;}
    else if(e>360 && s<360)	{
    	DrawSector(buffer, x0, y0, r, s, 360, color);
        s = 0;
        e = e-360;
    }

	int radius = r;
	int p = (5-(radius<<2))>>2;
	int x = 0;
	int y = radius;

	float slope = ((float)x/(float)y);
	int angle = (int)(((((((ARC_A*(slope*slope))+ARC_B)*(slope*slope)) + ARC_C)*slope)*180)/PI);
	if (x<=y){
		if (90-angle >= s 	 && 90-angle <= e)		{sector_putpixel(buffer, x0, y0, x0-y, y0+x, color);}
		if (angle >= s 		 && angle <= e)			{sector_putpixel(buffer, x0, y0, x0-x, y0+y, color);}
		if (180 - angle >= s && 180 - angle <= e)	{sector_putpixel(buffer, x0, y0, x0-x, y0-y, color);}
		if (angle + 90 >= s  && angle + 90 <= e)	{sector_putpixel(buffer, x0, y0, x0-y, y0-x, color);}
		if (270 - angle >= s && 270 - angle <= e)	{sector_putpixel(buffer, x0, y0, x0+y, y0-x, color);}
		if (angle + 180 >= s && angle + 180 <= e)	{sector_putpixel(buffer, x0, y0, x0+x, y0-y, color);}
		if (360 - angle >= s && 360 - angle <= e)	{sector_putpixel(buffer, x0, y0, x0+x, y0+y, color);}
		if (angle + 270 >= s && angle + 270 <= e)	{sector_putpixel(buffer, x0, y0, x0+y, y0+x, color);}
	}
	while(x<=y){
		x+=1;
		if(p<0){p += (x<<1)+1;}
		else{
			y -= 1;
			p += ((x-y)<<1)+1;
		}
		slope = ((float)x/(float)y);
		angle = (int)(((((((ARC_A*(slope*slope))+ARC_B)*(slope*slope)) + ARC_C)*slope)*180)/PI);
		if (x<=y){
			if (90-angle >= s 	 && 90-angle <= e)		{sector_putpixel(buffer, x0, y0, x0-y, y0+x, color);}
			if (angle >= s 		 && angle <= e)			{sector_putpixel(buffer, x0, y0, x0-x, y0+y, color);}
			if (180 - angle >= s && 180 - angle <= e)	{sector_putpixel(buffer, x0, y0, x0-x, y0-y, color);}
			if (angle + 90 >= s  && angle + 90 <= e)	{sector_putpixel(buffer, x0, y0, x0-y, y0-x, color);}
			if (270 - angle >= s && 270 - angle <= e)	{sector_putpixel(buffer, x0, y0, x0+y, y0-x, color);}
			if (angle + 180 >= s && angle + 180 <= e)	{sector_putpixel(buffer, x0, y0, x0+x, y0-y, color);}
			if (360 - angle >= s && 360 - angle <= e)	{sector_putpixel(buffer, x0, y0, x0+x, y0+y, color);}
			if (angle + 270 >= s && angle + 270 <= e)	{sector_putpixel(buffer, x0, y0, x0+y, y0+x, color);}
		}
	}
}