#include <stdio.h>
#include <iostream>
#include <iomanip>
int ones=0,twos=0,fives=0;
int target;
int casenum=0;

int max;
bool isvalid(){
    return(1*ones+2*twos+5*fives==target);
}
void dfs(int layer){
    if(layer==1){
        for(int i=0; i<=target/5; i++){
            fives+=i;
            dfs(2);
            fives-=i;
        }
        return;
    }
    if(layer==2){
        for(int i=0;i <=target/2; i++){
            twos+=i;
            dfs(3);
            twos-=i;
        }
        return;
    }
    if(layer==3){
        for(int i=0; i<=target; i++){
            ones+=i;
            if(isvalid()){
                casenum++;
                std::cout << std::setfill('0') << std::setw(3) << casenum;
                std::cout << std::setfill(' ') << std::setw(12) << ones 
                            << std::setfill(' ') << std::setw(12)<< twos 
                            << std::setfill(' ') << std::setw(12)<< fives <<std::endl;
                ones=0;
                return;
            }
            ones-=i;
        }
        return;
    }
}
int main(){
    scanf("%d",&target);
    int layer=1;
    dfs(1);
}
