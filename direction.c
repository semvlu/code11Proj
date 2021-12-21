#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
int direction(int *, int, int);

int direction(int *d, int width, int m)
{
    if((d[1] <= width) && d[2] <= width && d[3] > width && d[4]>width &&
    d[5] <= width)
    {
        if(d[m-4] <= width && d[m-3] <= width && d[m-2] > width && d[m-1] > width &&
        d[m] <= width)
        {
            return 1;
        }
    }

    if((d[1] <= width) && d[2] > width && d[3] > width && d[4] <= width && d[5] <= width)
    { 
        if(d[m-4] <= width && d[m-3] > width && d[m-2] > width && d[m-1] <= width &&
        d[m] <= width)
        { 
            return 0;
        } 
    }
    return -1; //error 
}