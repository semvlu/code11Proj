#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
#include<math.h>

int decode(int a[],int d[],int m,int n) //convert to decimal then to characters, return -1 if bad code
{
	int j=0;
	int i=0;
	for(i=6;i<=m-11;i=i+6){
		if(a[i+4]==1){
			d[j]=1;
		}
		if(a[i+3]==1){
			d[j]=d[j]+2;
		}
		if(a[i+2]==1){
			d[j]=d[j]+4;
		}
		if(a[i+1]==1){
			d[j]=d[j]+8;
		}
		if(a[i]==1){
			d[j]=d[j]+16;
		}
		j++;
	}
	for(j=0;j<n+2;j++){
		switch(d[j]){		
			case 16:
				d[j]=0;
				break;
			case 18:
				d[j]=1;
				break;
			case 3:
				d[j]=2;
				break;
			case 20:
				d[j]=3;
				break;
			case 12:
				d[j]=4;
				break;
			case 24:
				d[j]=5;
				break;
			case 5:
				d[j]=6;
				break;
			case 9:
				d[j]=7;
				break;
			case 17:
				d[j]=8;
				break;
			case 1:
				d[j]=9;
				break;
			case 4:
				d[j]=-1;		//-1 means "-"
				break;
			case 6:
				d[j]=-2;		//start/stop
				break;
			default:
				return -1;
				//break
		}
	}
	return 0;
}
