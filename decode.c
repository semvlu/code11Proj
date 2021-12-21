#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
void decode(int *, int, int, int); 
void decode(int *d,int width,int m,int time)
{ 
    char s[100]="";
    int count=0, sum=0, weight=16, index=0, count2=0; 
    if(d[6] <= width)
    {
        for(int i = 7; i <= m; i++)
        { 
            count2++;
            if(count2 % 6 == 0)
            {
                if( !(d[i] <= width))
                {
                    printf("Case %d: bad code\n" , time);
                    return ; 
                }
                continue;
            }
            count++; 

            if(d[i] <= width)
            {
                //do nothing 
            }
            else if(d[i] > width)
            { 
                sum += weight;
            }
            weight /= 2; 

            if(count % 5 == 0)
            {
                switch(sum)
                { 
                    case 16:
                        s[index] = '0'; 
                        break;
                    case 18:
                        s[index] ='1';
                        break; 
                    case 3: 
                        s[index] ='2';
                        break; 
                    case 20: 
                        s[index] = '3';
                        break; 
                    case 12: 
                        s[index] = '4';
                        break; 
                    case 24: 
                        s[index] = '5';
                        break; 
                    case 5: 
                        s[index] = '6';
                        break; 
                    case 9: 
                        s[index] = '7';
                        break; 
                    case 17: 
                        s[index] = '8';
                        break; 
                    case 1: 
                        s[index] = '9';
                        break;
                    case 4:
                        s[index] = '-';
                        break;
                    default:
                        printf("Case %d: bad code\n",time); 
                        return;
                }
                index++; 
                weight = 16; 
                sum = 0;
            } 
        }
        count = 0, sum = 0, weight = 16, count2 = 0;
        //check character
        char c, e;
        for(int i = m + 1; i <= m + 12; i++)
        {
            count2++; 
            if(count2 % 6 == 0)
            {
                if(!(d[i] <= width))
                {
                    printf("Case %d: bad code\n",time); 
                    return;
                }
                continue; 
            }
            count++; 

            if(d[i] <= width)
            {
                //do nothing 
            }

            else if(d[i]>width)
            { 
                sum += weight;
            }
            weight /= 2; 

            if(count % 5 == 0)
            {
                switch(sum)
                {  
                    case 16:
                        c = '0'; 
                        break; 
                    case 18: 
                        c ='1'; 
                        break; 
                    case 3: 
                        c ='2'; 
                        break; 
                    case 20: 
                        c = '3'; 
                        break; 
                    case 12: 
                        c = '4'; 
                        break; 
                    case 24: 
                        c = '5'; 
                        break; 
                    case 5:
                        c = '6';
                        break;
                    case 9:
                        c = '7';
                        break;
                    case 17:
                        c = '8';
                        break;
                    case 1:
                        c = '9';
                        break;
                    case 4:
                        c = '-';
                        break;
                    default:
                        printf("Case %d: bad code\n",time); 
                        return;
                } 
                if(count == 5)
                {
                    if(checkC(s,c,index) !=1 )
                    {  
                        printf("Case %d: bad C\n",time); 
                        return ;
                    }
                    e = c; // record c check character 
                }
                else
                {
                    if(checkK(s,c,index,e) !=1)
                    {
                        printf("Case %d: bad K\n",time);
                        return; 
                    }
                } 
                weight = 16; 
                sum = 0;
            }
        }
        s[index] = '\0';
        printf("Case %d: %s\n" , time,s); 
    }
    else
    {
        printf("Case %d: bad code\n", time);
    }
}