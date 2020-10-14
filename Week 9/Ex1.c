#include<stdio.h>
#include <stdint.h>

int pNum[1000];
int pAge[1000];

int buffer (){
	int bufint;
	printf("Enter the buffer size: ");
	scanf("%d",&bufint);
	return bufint;
}

int main(){
	int bSize= buffer();;
    int i;
    int x;
    float ratio;
    int cnt=0;
    float hit=0,miss=0;
    
    FILE* fp = fopen("ex1.txt", "r");
    if(fp == NULL)
    {
        printf("Error opening file\n");
        return 1;
    }
    
        for(i=0;i<cnt;i++)pAge[i]>>=1;
        int fnd = 0;
        for(i=0;i<cnt;i++)if(pNum[i]==x){
            fnd = 1;
            pAge[i]+=(1<<8);
            hit++;
            break;
        }
        if(!fnd){
            miss++;
            if(cnt<bSize){
                pNum[cnt]=x;
                pAge[cnt]=1<<8;
                cnt++;
            }
            else{
                int minInd,minAge = 1<<10;
                for(i=0;i<cnt;i++){
                    if(pAge[i]<minAge){
                        minInd = i;
                        minAge = pAge[i];
                    }
                }
                pNum[minInd]=x;
                pAge[minInd]=(1<<8);
            }
        }
        
    ratio = hit/miss;
    printf("Hit/Miss ratio is : %f",ratio);
}
