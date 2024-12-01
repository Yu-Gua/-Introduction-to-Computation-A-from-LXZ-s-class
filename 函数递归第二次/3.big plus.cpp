#include <iostream>
#include <stdio.h>
#include <sstream>
#include <string>
#include <algorithm>
#include <cmath>
const int N=210;

int input(int number[]){
    //std::cin.ignore();
    int i=0; 
    char c=std::cin.get();
    while(c !='\n'){
        number[i]=c-'0';
        i++;
        c=std::cin.get();
    }
    return i;
}
void reverse(int number[],int size){
    int newnumber[N];
    for(int i=size-1; i>=0; i--){
        newnumber[size-i-1]=number[i];
    }
    for(int i=0; i<size; i++){
        number[i]=newnumber[i];
    }
}
void calculate(int a[],int b[],int size){
    int sum[N]={0};
    for(int i=0; i<size; i++){
        sum[i]=a[i]+b[i];
    }
    for(int i=0; i<size+1; i++){
        if(sum[i]>=10){
            sum[i]-=10;
            sum[i+1]++;
        }
    }
    for(int i=0; i<size+1; i++){
        a[i]=sum[i];
    }
}
int main(){
    int num;
    scanf("%d",&num);
    std::cin.ignore();
    for(int i=0; i<num; i++){
        int a[N]={0};
        int b[N]={0};
        int asize=input(a);
        int bsize=input(b);
        //printf("%d %d\n",asize, bsize);
        reverse(a,asize);
        reverse(b,bsize);
        int more=std::max(asize,bsize);
        calculate(a,b,more);
        bool flagOfZeroForward=true;
        bool emptyoutput=true;
        for(int i=more; i>=0; i--){
            if(a[i]!=0){
                flagOfZeroForward=false;
                emptyoutput=false;
            }
            if(!flagOfZeroForward)printf("%d",a[i]);
        }
        if(emptyoutput){
            printf("0");
        }
        printf("\n");
    }
    
    return 0;
}