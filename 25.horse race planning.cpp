#include <stdio.h>
#include <algorithm>
int num;
const int M=1010;
int main(){
    scanf("%d",&num);
    while(num!=0){
        int money=0;
        int Tian[M];
        int Qi[M];
        for(int i=0; i<num; i++){
            scanf("%d",&Tian[i]);
        }
        for(int i=0; i<num;i++ ){
            scanf("%d",&Qi[i]);
        }
        std::sort(Tian,Tian+num);
        std::sort(Qi,Qi+num);
        int *tianstart=&Tian[0],*tianend=&Tian[num-1];
        int *qistart=&Qi[0],*qiend=&Qi[num-1];
        while(tianstart<=tianend){
            if(*tianstart>*qistart){
                money+=200;
                tianstart++;
                qistart++;
            }
            else if(*tianstart<*qiend){
                money-=200;
                tianstart++;
                qiend--;
            }
            else{
                money=money;
                tianstart++;
                qiend--;
            }
        }
        printf("%d\n",money);
        scanf("%d",&num);
    }
}
// 1 2 3 4 5 6 7 8 9 11 Qi
//2 3 4 5 6 7 8 9 10 11 Tian