#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
const int lim=100;
std::string table="0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
int toNumber(char c){
    int num=table.find(c);
    return num;
}
char toch(int num){
    return table[num];
}
void turn(std::string& num,int base,int newbase){
    int mod=0;
    std::string quo;
    std::string newnum;
    
    while(num.length()!=0){
        
        for(int i=0; i<num.size(); i++){
            mod=mod*base+toNumber(num[i]);
            quo.push_back(toch(mod/newbase));
            mod=mod%newbase;
        }
        while(quo[0]=='0'){
            quo=quo.substr(1);
        }
        num=quo;
        quo.clear();
        char mod_ch=toch(mod);
        newnum=mod_ch+newnum;
        mod=0;
    }
    num=newnum;
}
int main(){
    int cases;
    scanf("%d",&cases);
    for(int i=0; i<cases; i++){
        char num[lim]={'0'};
        int base,newbase;
        scanf("%d",&base);
        std::cin.ignore();
        char c=std::cin.get();
        int it=0;
        while(c!=','){
            num[it]=c;
            it++;
            c=std::cin.get();
        }
        std::string number=num;
        scanf("%d",&newbase);
        //printf("%d %d",base,newbase);
        bool allzero=true;
        for(int i=0; i<number.size();i++){
            if(number[i]!='0'){
                allzero=false;
                break;
            }
        }
        if(allzero){
            printf("0\n");
            continue;
        }
        turn(number,base,newbase);
        
        std::cout<< number << std::endl;
    }
}