#include <stdlib.h>
#include "graphic.h"

void swap (int *a, int *b){
    *a ^= *b;
    *b ^= *a;
    *a ^= *b;
} 

void DrawTriangle(int **buffer, int x0, int y0, int x1, int y1, int x2, int y2, int color, bool fill){
    if(fill){
        int a, b, y, last;
        if (y0 > y1){
            swap (&y0, &y1);
            swap (&x0, &x1);
        }
        if (y1 > y2){
            swap (&y2, &y1);
            swap (&x2, &x1);
        }
        if (y0 > y1){
            swap (&y0, &y1);
            swap (&x0, &x1);
        }
    
        if (y0 == y2){
            a = b = x0;
            
            if (x1 < a)         {a = x1;}
            else if (x1 > b)    {b = x1;}
            
            if (x2 < a)         {a = x2;}
            else if (x2 > b)    {b = x2;}
            
            DrawHorzLine(buffer, a, y0, b - a + 1, color);
            return;
        }
    
        int dx01 = x1 - x0, dy01 = y1 - y0, dx02 = x2 - x0, dy02 = y2 - y0, dx12 = x2 - x1, dy12 = y2 - y1, sa = 0, sb = 0;
    
        if (y1 == y2)   {last = y1;}
        else            {last = y1 - 1;}
    
        for (y = y0; y <= last; y++){
            a = x0 + sa / dy01;
            b = x0 + sb / dy02;
            sa += dx01;
            sb += dx02;
            
            if (a > b){swap (&a, &b);}
            
            DrawHorzLine(buffer, a, y, b - a + 1, color);
        }
    
        sa = dx12 * (y - y1);
        sb = dx02 * (y - y0);
        
        for (; y <= y2; y++){
            a = x1 + sa / dy12;
            b = x0 + sb / dy02;
            sa += dx12;
            sb += dx02;
            
            if (a > b){swap (&a, &b);}
            
            DrawHorzLine(buffer, a, y, b - a + 1, color);
        }
    }
    else{
        DrawLine(buffer, x0, y0, x1, y1, color);
		DrawLine(buffer, x1, y1, x2, y2, color);
		DrawLine(buffer, x2, y2, x0, y0, color);
    }
}
