#include <stdlib.h>
#include "graphic.h"

void arc_putpixel(int **buffer, int x0, int y0, int color){
    if (x0 >= 0 && x0 < WIDTH){
        if (y0 >= 0 && y0 < HEIGHT) {buffer[y0][x0] = color;}
        if (y0+1 >= 0 && y0+1 < HEIGHT) {buffer[y0+1][x0] = color;}
    }
    if (x0+1 >= 0 && x0+1 < WIDTH){
        if (y0 >= 0 && y0 < HEIGHT) {buffer[y0][x0+1] = color;}
        if (y0+1 >= 0 && y0+1 < HEIGHT) {buffer[y0+1][x0+1] = color;}
    }
}

void DrawArc(int **buffer, int x0, int y0, int r, int thick, int start_angle, int end_angle, int color){
	if(end_angle>360 && start_angle>360)		{start_angle %= 360;    end_angle %= 360;}
    if(end_angle<=start_angle || r<4) 		    {return;}
    else if((end_angle - start_angle) >= 360)	{start_angle = 0;	end_angle = 360;}
    else if(end_angle>360 && start_angle<360)	{
        DrawArc(buffer, x0, y0, r, thick, start_angle, 360, color);
        start_angle = 0;
        end_angle -= 360;
    }

    for(int t=0;t<thick;t++){
        int radius = r + t - 1;
        int p = (5-(radius<<2))>>2;
        int x = 0;
        int y = radius;

        float slope = ((float)x/(float)y);
        int angle = (int)(((((((ARC_A*(slope*slope))+ARC_B)*(slope*slope)) + ARC_C)*slope)*180)/PI);
        if (x<=y){
            if (90 - angle >= start_angle 	&& 90 - angle <= end_angle)		{arc_putpixel(buffer, x0-y, y0+x, color);}
            if (angle >= start_angle 		&& angle <= end_angle)			{arc_putpixel(buffer, x0-x, y0+y, color);}
            if (180 - angle >= start_angle  && 180 - angle <= end_angle)	{arc_putpixel(buffer, x0-x, y0-y, color);}
            if (angle + 90 >= start_angle   && angle + 90 <= end_angle)	    {arc_putpixel(buffer, x0-y, y0-x, color);}
            if (270 - angle >= start_angle  && 270 - angle <= end_angle)	{arc_putpixel(buffer, x0+y, y0-x, color);}
            if (angle + 180 >= start_angle  && angle + 180 <= end_angle)	{arc_putpixel(buffer, x0+x, y0-y, color);}
            if (360 - angle >= start_angle  && 360 - angle <= end_angle)	{arc_putpixel(buffer, x0+x, y0+y, color);}
            if (angle + 270 >= start_angle  && angle + 270 <= end_angle)	{arc_putpixel(buffer, x0+y, y0+x, color);}
        }
        while(x<=y){
            x += 1;
            if(p<0){p += (x<<1)+1;}
            else{
                y -= 1;
                p += ((x-y)<<1)+1;
            }
            slope = ((float)x/(float)y);
            angle = (int)(((((((ARC_A*(slope*slope))+ARC_B)*(slope*slope)) + ARC_C)*slope)*180)/PI);
            if (x<=y){
                if (90 - angle >= start_angle   && 90 - angle <= end_angle)		{arc_putpixel(buffer, x0-y, y0+x, color);}
                if (angle >= start_angle 	    && angle <= end_angle)			{arc_putpixel(buffer, x0-x, y0+y, color);}
                if (180 - angle >= start_angle  && 180 - angle <= end_angle)	{arc_putpixel(buffer, x0-x, y0-y, color);}
                if (angle + 90 >= start_angle   && angle + 90 <= end_angle)	    {arc_putpixel(buffer, x0-y, y0-x, color);}
                if (270 - angle >= start_angle  && 270 - angle <= end_angle)	{arc_putpixel(buffer, x0+y, y0-x, color);}
                if (angle + 180 >= start_angle  && angle + 180 <= end_angle)	{arc_putpixel(buffer, x0+x, y0-y, color);}
                if (360 - angle >= start_angle  && 360 - angle <= end_angle)	{arc_putpixel(buffer, x0+x, y0+y, color);}
                if (angle + 270 >= start_angle  && angle + 270 <= end_angle)	{arc_putpixel(buffer, x0+y, y0+x, color);}
            }
        }
    }
}