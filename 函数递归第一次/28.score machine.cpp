#include <stdio.h>
#include <algorithm>
#include <string>
#include <iostream>
std::string operations;
int target;
int G(int x){
    return x*2+2;
}
int N(int x){
    return x*2+1;
}
bool flag=false;
void machine(int score){
    if(flag){
        return;
    }
    //std::cout << operations << std::endl;
    if(score==target){
        std::cout << operations << std::endl;
        flag=true;
        return;
    }
    if(score>target){
        return;
    }
    int newscore=G(score);
    operations.push_back('G');
    machine(newscore);
    operations.pop_back();
    newscore=N(score);
    operations.push_back('N');
    machine(newscore);
    operations.pop_back();
}
int main(){
    scanf("%d",&target);
    machine(0);
}