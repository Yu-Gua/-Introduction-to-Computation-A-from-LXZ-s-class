#include <stdio.h>
#include <algorithm>
int factorA[1000]={0};
int factorB[1000]={0};

void div(int fac,int num,int* factor){
    
    if(num==1){
        return;
    }
    if(num%fac!=0){
        div(fac+1,num,factor);
        return;
    }
    else *factor=fac;
    if(num%(fac*fac)==0){
        div(fac,num/fac,factor);
        return;
    }
    else {
        div(fac,num/fac,factor+1);
        return;
    }
}
int main(){
    int a,b;
    scanf("%d,%d",&a,&b);
    int *ap=factorA,*bp=factorB;
    div(2,a,ap);
    div(2,b,bp);
    bool flag=true;
    for(int i=0; i<100; i++){
        if(factorB[i]!=factorA[i]) {
            flag=false;
            break;
        }
        if(factorA[i]==0 && factorB[i]==0){
            break;
        }
    }
    if(flag){
        printf("YES");
    }
    else printf("NO");
}