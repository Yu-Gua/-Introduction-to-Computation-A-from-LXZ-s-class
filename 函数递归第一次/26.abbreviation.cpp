#include <stdio.h>
#include <string>
#include <iostream>
std::string abr;
std::string origin;
bool isABR(int index,int from){
    if(index==abr.size()){
        return true;
    }
    if(origin.find(abr[index],from)==std::string::npos){
        return false;
    }
    int newfrom=origin.find(abr[index],from);
    return(isABR(index+1,newfrom+1));
}
int main(){
    int N;
    scanf("%d",&N);
    std::cin.ignore();
    for(int i=0; i<N; i++){
        abr.clear();
        origin.clear();
        std::getline(std::cin,abr,':');
        std::getline(std::cin,origin);
        //std::cin.ignore();
        std::cout << abr << ' ' << origin << std::endl;
        int index=0;
        if(isABR(0,0)&&abr.size()<origin.size()){
            printf("YES\n");
        }
        else printf("NO\n");
    }
}