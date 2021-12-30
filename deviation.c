#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
#include<math.h>

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
#include<math.h>

int deviation(int a[],int b[],int m) //return 1 if ok   -1 if bad code
{		
	int nrwmin=a[0],widmin=200,widmax=0;
	double mid=0;		
	for(int i=0;i<m;i++){
		if(a[i]<nrwmin){
			nrwmin=a[i];
		}
		if(a[i]>widmax){
			widmax=a[i];
		}
	}
	mid=(nrwmin+widmax)/2.0;
	if(nrwmin>=widmax*0.9){
		for(int i=0;i<m;i++){
			if(a[i]<mid){
				a[i]=0;
			}
			else{
				a[i]=1;
			}
		}
		return 1;
	}
	for(int i=0;i<m;i++){
		if(b[i]<mid){
			b[i]=b[i]*2;
		}
		if(b[i]>widmax){
			widmax=b[i];
		}
		if(b[i]<widmin){
			widmin=b[i];
		}
	}
	if(widmax*0.95>widmin*1.05){
		return -1;		//bad code
	}
	else{
		for(int i=0;i<m;i++){
			if(a[i]<mid){
				a[i]=0;
			}
			else{
				a[i]=1;
			}
		}
		return 1;
	}
}
