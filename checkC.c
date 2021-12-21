#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
int checkC(char *, char, int);

int checkC(char * s,char c,int n)
{
    int correct,sum=0,weight; 
    if(c == '-')
    {
        correct = 10; 
    }
    else
    {
        correct = c-'0'; 
    }
    for(int i=1;i<=n;i++)
    { 
        if(s[i-1] == '-')
        {
            weight = 10; 
        }
        else
        {
            weight = s[i-1] - '0'; 
        }
        sum += ((n-i)%10+1) * weight; 
    }
    if(sum % 11 == correct)
    { 
        return 1;
    }
    else
    {
        return 0;
    } 
}