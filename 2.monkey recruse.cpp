#include <stdio.h>
bool check(int name, int apple, int remain,int monkeys){
    if(name==1){
        return apple%monkeys == remain;
    }

    if(apple%(monkeys-1)!=0){
        return false;
    }
    int nextapple=apple/(monkeys-1)*monkeys+remain;
    return check(name-1,nextapple,remain,monkeys);

}
int calcu(int& apple, int remain, int monkeys,int name){
    if(name==1){
        return apple;
    }
    apple=apple/(monkeys-1)*monkeys+remain;
    return calcu(apple,remain,monkeys,name-1);
}
int main(){
    int monkeys,remain;
    scanf("%d %d",&monkeys,&remain);
    int appleget=1;
    for(; ; appleget++){
        int applefirst=appleget*monkeys+remain;
        if(check(monkeys,applefirst,remain,monkeys)){
            printf("%d",calcu(applefirst,remain,monkeys,monkeys));
            break;
        }
    }
}