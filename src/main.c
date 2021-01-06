#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "graphic.h"

void main()
{
    int** buffer = malloc(sizeof(int*) * HEIGHT);
    for(int y=0;y<HEIGHT;y++){
        buffer[y] = calloc(sizeof(int), WIDTH);
    }

    DrawLine(buffer, 310, 200, 17, 43, 0x00FFFF00);
    DrawRectangle(buffer, 90, 20, 200, 65, 0x00FF00FF, true);
    DrawRoundedRectangle(buffer, 77, 54, 60, 70, 20, 0x0000FFFF, false);
    DrawTriangle(buffer, 77, 54, 100, 0, 163, 169, 0x00FFF00F, true);
    DrawCircle(buffer, 160, 160, 50, 0x00F00FFF, false);
    DrawSector(buffer, 10, 175, 25, 30, 271, 0x00FF00FF);
    DrawEllipse(buffer, 140, 175, 60, 300, 0x00888888, false);  

    
    for(int y=0;y<HEIGHT;y++){
        for(int x=0;x<WIDTH;x++){
            printf("%d, ", buffer[y][x]);
        }
        printf("\n");
    }printf("\n");
    
}
