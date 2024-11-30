#include <stdio.h>
#include <algorithm>
#include <string>
#include <iostream>
#include <vector>

bool isAlpha(char& c){
    return((c>='a' && c<='z') || (c>='A' && c<='Z'));
}
bool isquote(char& c){
    return(c==39);
}
std::string getword(std::string& tmp){
    char c=std::cin.get();
    bool alpha=isalpha(c) || isquote(c);
    if(alpha){
        
        return(c+getword(tmp));
    }
    else 
        {
            return(tmp);
        }
}
int main(){
    std::vector <std::string> spell;  //Haven't
    std::vector <int> frequency;

    while(!std::cin.eof()){
        std::string tmp;
        tmp=getword(tmp);
        if(!tmp.empty()){
            auto index=std::find(spell.begin(),spell.end(),tmp);
            if(index ==spell.end()){
                spell.push_back(tmp);
                frequency.push_back(1);
            }
            else{
                int i=index-spell.begin();
                frequency.at(i)++;
            }
        }
    }
    for(int i=0; i<spell.size(); i++){
        std::cout << spell[i] << ' ' << frequency[i] << std::endl;
    }
}