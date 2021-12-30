#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
#include<math.h>

int checkspace(int a[],int m)	//return 0 if ok, -1 if bad code
{		
	int i=5;
	while(i<=m-6){
		if(a[i]!=0){
			return -1;
		}
		else{
			i=i+6;
		}
	}
	return 0;
}
