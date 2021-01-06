#include <stdbool.h>
#include "graphic.h"

void DrawRectangle(int** buffer, int x, int y, int width, int height, int color, bool fill){
	if (fill) {
		while (height--) {
			DrawHorzLine(buffer, x, y+height, width, color);
		}
	}
	else {
		DrawHorzLine(buffer, x, y, width, color);
		DrawHorzLine(buffer, x, y+height-1, width, color);
		DrawVertLine(buffer, x, y, height, color);
		DrawVertLine(buffer, x+width-1, y, height, color);
	}
}

void DrawRoundedRectangle(int** buffer, int x, int y, int width, int height, int radius, int color, bool fill){
	int x1 = 0;
	int y1 = radius;
	int xEnd = x + width - 1;
	int yEnd = y + height - 1;
	int xAddRadius = x + radius;
	int yAddRadius = y + radius;
	int xEndSubRadius = xEnd - radius;
	int diameter = 2 * radius;
	int tSwitch = 3 - diameter;

	if (fill){
		DrawRectangle(buffer, xAddRadius, y, width - diameter, height, color, true);
		while (x1 <= y1){
		    int h = 2 * y1 + height - diameter;
			DrawVertLine(buffer, xAddRadius - x1, yAddRadius - y1, h, color);
			DrawVertLine(buffer, xEndSubRadius + x1, yAddRadius - y1, h, color);

			h = 2 * x1 + height - diameter;
			DrawVertLine(buffer, xAddRadius - y1, yAddRadius - x1, h, color);
			DrawVertLine(buffer, xEndSubRadius + y1, yAddRadius - x1, h, color);
			
            if (tSwitch < 0){
                tSwitch += (4 * x1 + 6);
            }
            else{
                tSwitch += (4 * (x1 - y1) + 10);
                y1--;
            }
            x1++;
		}
	}
	else{
		DrawHorzLine(buffer, xAddRadius, y, width-diameter, color);
		DrawHorzLine(buffer, xAddRadius, yEnd, width-diameter, color);
		DrawVertLine(buffer, x, yAddRadius, height-diameter, color);
		DrawVertLine(buffer, xEnd, yAddRadius, height-diameter, color);
		
        while (x1 <= y1) {
            int yEndSubRadius = yEnd - radius;
            int points[8][2] = {
                { xAddRadius - x1,      yAddRadius - y1},
                { xAddRadius - y1,      yAddRadius - x1},
                { xEndSubRadius + x1,   yAddRadius - y1},
                { xEndSubRadius + y1,   yAddRadius - x1},
                { xEndSubRadius + x1,   yEndSubRadius + y1},
                { xEndSubRadius + y1,   yEndSubRadius + x1},
                { xAddRadius - x1,      yEndSubRadius + y1},
                { xAddRadius - y1,      yEndSubRadius + x1}
            };
            
            for (int i = 0; i < 8; i++) {
                if (points[i][0] >= 0 && points[i][1] >= 0 && points[i][0] < WIDTH && points[i][1] < HEIGHT) {
		               buffer[points[i][1]][points[i][0]] = color;
	            }
            }
            
            if (tSwitch < 0){
                tSwitch += (4 * x1 + 6);
            }
            else{
                tSwitch += (4 * (x1 - y1) + 10);
                y1--;
            }
            x1++;
        }
	}
}
