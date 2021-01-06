#include <stdlib.h>
#include "graphic.h"

void DrawCircle(int **buffer, int x0, int y0, int r, int color, bool fill){
	int x = (r^(-1))+1;
	int y = 0;
	int err = 2-(r<<1);
	int e2 = err;
	
	if(fill){
	    do {
			DrawVertLine(buffer, x0-x, y0-y, (y<<1)+1, color);
			DrawVertLine(buffer, x0+x, y0-y, (y<<1)+1, color);
    		e2 = err;
    		if (e2 <= y) {
    			err += ((++y)<<1)+1;
    			if (((x^(-1))+1 == y) && (e2 <= x)) {e2 = 0;}
    		}
    		else if (e2 > x) {err += ((++x)<<1) + 1;}
    	} while (x <= 0);
	}
	else{
	    do {
    	    if (x0+x >= 0 && x0+x < WIDTH){
                if (y0+y >= 0 && y0+y < HEIGHT) {buffer[y0+y][x0+x] = color;}
                if (y0-y >= 0 && y0-y < HEIGHT) {buffer[y0-y][x0+x] = color;}
            }
            if (x0-x >= 0 && x0-x < WIDTH){
                if (y0+y >= 0 && y0+y < HEIGHT) {buffer[y0+y][x0-x] = color;}
                if (y0-y >= 0 && y0-y < HEIGHT) {buffer[y0-y][x0-x] = color;}
            }
    		e2 = err;
    		if(e2 <= y){
    			err += ((++y)<<1)+1;
    			if (((x^(-1))+1 == y) && (e2 <= x)) {e2 = 0;}
    		}
    		else if(e2 > x) {err += ((++x)<<1) + 1;}
    	} while (x <= 0);
	}
}