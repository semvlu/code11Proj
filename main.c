#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
#include<math.h>
#include "deviation.c"
#include "direction.c"
#include "checkspace.c"
#include "decode.c"
#include "checkC.c"
#include "checkK.c"
#include "out.c"

int main()
{
	int m;
	int time=1;
	FILE *ptr=NULL;
	if((ptr=fopen("testcase.txt","r"))==NULL){
		puts("Couldn't open the file");
	}
	else{
		fscanf(ptr,"%d",&m);
		while(m!=0){
			if(m>150||m<29||(m-29)%6!=0){
				printf("Case %d: bad code\n",time);
				fscanf(ptr,"%d",&m);
				time++;
				continue;
			}
			else{
				int n=(m-23)/6;
				int a[m];		//the value inside will change from input to binary
				memset(a, 0, m * sizeof(int));
				int b[m];		//used to check width
				memset(b, 0, m * sizeof(int));
				for(int i=0;i<m;i++){		//input the values 
					fscanf(ptr,"%d",&a[i]);		
					if(a[i]<1||a[i]>200){
						printf("Case %d: bad code\n",time);
						break;		
					}
					else{
						b[i]=a[i];
					}
				}
				if(b[m-1]!=0){
					int convert=deviation(a,b,m);		//deviation processing + convert to 0、1 
					if(convert==-1){
						printf("Case %d: bad code\n",time);
						//continue;
					}
					else{		//now value in a[] are 0 and 1
						int dir=direction(a,m);		//check direction + reverse
						if(dir==0){		//bad code	
							printf("Case %d: bad code\n",time);
						}
						else{
							if(checkspace(a,m)!=-1){		//whether every space are 0
								int d[n+2];		//int d[n+2]={0};
								memset(d,0,(n+2)*sizeof(int));
								int result=decode(a,d,m,n);		//decode characters
								if(result==-1){
									printf("Case %d: bad code\n",time);
									//break;
								}
								else{
									int c=checkC(d,n);
									if(c==-1){
										printf("Case %d: bad C\n",time);
										//break;
									}
									else{
										int k=checkK(d,n);
										if(k==-1){
											printf("Case %d: bad K\n",time);
											//break;
										}
										else{
											out(d,n,time);
										}
									}
								}
							}
							else{
									printf("Case %d: bad code\n",time);
							}
						}
					}
				}
			}
			time++;
			fscanf(ptr,"%d",&m);
		}
	}
	fclose(ptr);
}