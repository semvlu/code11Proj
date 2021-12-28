#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
#include<math.h>

void out(int d[],int n,int time)
{
	printf("Case %d: ",time);
	for(int i=0;i<n;i++){
		if(d[i]==-1){
			printf("%c",'-');
		}
		else{
			printf("%d",d[i]);
		}
	}
	puts("");
}