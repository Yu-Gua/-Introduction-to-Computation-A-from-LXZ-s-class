#include <stdio.h>
#include <iostream>
#include <string>
bool check(std::string line){
    int half=line.size()/2;
    for(int i=0; i<half; i++){
        if(line[i]!=line[line.size()-1-i]) return false;
    }
    return true;
}
int main(){
    std::string line;
    
    while(std::cin){
        line.clear();
        char c=std::cin.get();
        if(!std::cin){
            break;
        }
        while(c!='\n'){
            if(isalpha(c))line.push_back(c);
            if(std::cin){
                c=std::cin.get();
            }
            else break;
        }
        if(check(line)) {printf("true\n");continue;}
        else {printf("false\n");continue;}
    }
}