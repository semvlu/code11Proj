#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
#include<math.h>

int checkK(int d[],int n)
{
	int chk=d[n+1];	//value that k suppose to be
	int sum=0;	//value to be %11
	int w;		//weight
	for(int i=0;i<n+1;i++){
		if(d[i]!=-1){
			w=d[i];
		}
		else{
			w=10;
		}
		sum=sum+((n-i)%9+1)*w;
	}
	if(sum%11==chk){
		return 0;
	}
	else{
		return -1;	//bad K
	}
}
