#include <stdio.h>
void ice(int n){
    if(n==1){
        return;
    }
    if(n%2==0){
        printf("%d/2=%d\n",n,n/2);
        ice(n/2);    
    }
    else{
        printf("%d*3+1=%d\n",n,3*n+1);
        ice(n*3+1);
    }
}
int main(){
    int n;
    scanf("%d",&n);
    ice(n);
    printf("End");
}