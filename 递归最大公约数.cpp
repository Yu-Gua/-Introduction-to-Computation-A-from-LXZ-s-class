#include <stdio.h>
int mcf(int a, int b){
    if(a%b == 0){
        return b;
    }
    if(a > b){
        return mcf(a, a%b);
    }
    else{
        return mcf(b, b%a);
    }
}
int main(){
    int a,b;
    while(true){scanf("%d %d",&a,&b);
    int out= mcf(a,b);
    printf("%d\n",out);
    }

}