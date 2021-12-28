#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
#include<math.h>

int direction(int a[],int m){		//return 1 if ok   0 if bad code
	if(a[0]==0&&a[1]==0&&a[2]==1&&a[3]==1&&a[4]==0&&a[m-5]==0&&a[m-4]==0&&a[m-3]==1&&a[m-2]==1&&a[m-1]==0){		//upright
		return 1;
	}
	else if(a[0]==0&&a[1]==1&&a[2]==1&&a[3]==0&&a[4]==0&&a[m-5]==0&&a[m-4]==1&&a[m-3]==1&&a[m-2]==0&&a[m-1]==0){		//invert
		int count=0;	
		int hold;
		while(count<(m-1)/2){		//reverse
			hold=a[count];
			a[count]=a[m-count-1];
			a[m-count-1]=hold;
			count++;
		}
		return 1;
	}
	else{
		return 0;
	}
}