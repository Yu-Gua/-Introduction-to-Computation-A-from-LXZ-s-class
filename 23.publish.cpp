#include <string>
#include <stdio.h>
#include <iostream>
#include <sstream>
std::string word;
void  getword(std::string& word){
    if(!std::cin){
        return;
    }
    char c=std::cin.get();
    while(c!=' '&& c!='\n' && std::cin){
        word+=c;
        c=std::cin.get();
    }
    return;
}
void printLine(std::string& tmp){
    //std::string word;
    //std::cout << tmp << std::endl;
    if(!std::cin){
        return;
    }
    if(word.size()==0) getword(word);
    int sizeword=word.size();
    if(tmp.size()+sizeword>80){
        return;
    }
    else{
        tmp=tmp+word+' ';
        word.clear();
        if(std::cin)printLine(tmp);
    }
}
int main(){
    int trash;
    scanf("%d",&trash);
    std::cin.ignore();
    std::stringstream flow;
    while(std::cin){
        std::string tmp;
        
        printLine(tmp);
        tmp.pop_back();
        if(!std::cin){
            tmp.pop_back();
        }
        std::cout << tmp << '\n';
    }
   
    
}