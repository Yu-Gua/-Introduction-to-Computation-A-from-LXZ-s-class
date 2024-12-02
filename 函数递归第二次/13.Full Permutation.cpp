#include <stdio.h>
#include <string>
#include <iostream>
std::string line;
std::string out;
const int lim=10;
bool isUsed[lim];
void init(){
    for(int i=0; i<lim ; i++){
        isUsed[i]=false;
    }
}
void permutation(int index,std::string& out){
    if(index==line.size()){
        std::cout << out << std::endl;
        return ;
    }
    for(int i=0; i<line.size(); i++){
        if(!isUsed[i]){
            out[index]=line[i];
            isUsed[i]=true;
            permutation(index+1,out);
            //递归
            isUsed[i]=false;
            //回溯
        }
    }
}
int main(){
    std::getline(std::cin,line);
    out=line;
    permutation(0,out);
}