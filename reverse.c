#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
void reverse(int *, int);

void reverse(int *f,int m)
{ 
    for(int j =1; j < m; j++, m--)
    {
        swap(&f[j],&f[m]); 
    }
}