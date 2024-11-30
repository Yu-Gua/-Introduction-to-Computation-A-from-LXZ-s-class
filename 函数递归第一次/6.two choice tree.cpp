#include <stdio.h>
#include <vector>
void dot(int n,std::vector<int>& path){
    path.push_back(n);
    if(n == 1){
        return;
    }
    if(n%2 == 0){
        dot(n/2,path);
    }
    else{
        dot((n-1)/2,path);
    }
}
int main(){
    int a,b;
    scanf("%d %d",&a,&b);
    std::vector<int> pathA,pathB;
    dot(a,pathA);
    dot(b,pathB);
    for(int j=0; j<pathA.size() && j<pathB.size(); j++){
        auto itA=pathA.end()-1-j;
        auto itB=pathB.end()-1-j;
        if(*itA == *itB){
            if(itA == pathA.begin() || itB == pathB.begin()){
                printf("%d",*itA);
            }
            continue;
        }
        
        else{
            printf("%d",*(itA+1));
            break;
        }
    }   
}