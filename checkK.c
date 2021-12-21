#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
int checkK(char *, char, int, char); 

int checkK(char *s,char c,int n,char Ccheck)
{ 
    // c represents the user input ,Ccheck is last time we calculated
    int sum=0,weight,correct; 
    if(c=='-')
    {
        correct = 10; 
    }
    else
    {
        correct = c- '0'; 
    }
    for(int i =1; i <= n+1; i++)
    { 
        if(i == n+1)
        {
            if(Ccheck =='-')
            { 
                weight = 10;
            }
            else
            {
                weight = Ccheck-'0';
            } 
        }
        else
        {
            if(s[i-1]=='-')
            { 
                weight = 10;
            }
            else
            {
                weight = s[i-1] - '0';
            } 
        }
        sum += ((n-i+1)%9+1) * weight; 
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