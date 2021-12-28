#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
#include<math.h>

int checkC(int d[],int n)
{
	int chk=d[n];		//value that c support to be
	int sum=0;		//value to be %11
	int w;		//weight
	for(int i=0;i<n;i++){
		if(d[i]!=-1){
			w=d[i];
		}
		else{
			w=10;
		}
		sum=sum+((n-i-1)%10+1)*w;
	}
	if(sum%11==chk){
		return 0;
	}
	else{
		return -1;		//bad C
	}
}