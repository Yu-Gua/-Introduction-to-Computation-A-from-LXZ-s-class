#include <stdio.h>
double L(int n,int x){
    if(n==0) return 1;
    if(n==1) return (double)x;
    return ((double)(2*n-1) * (double)x * L(n-1,x) - (double)(n-1) * L(n-2,x)) / (double)n;
}
int main(){
    int n,x;
    scanf("%d %d",&n,&x);
    printf("%g",L(n,x));
}