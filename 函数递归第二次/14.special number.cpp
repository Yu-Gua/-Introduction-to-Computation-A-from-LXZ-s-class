#include <stdio.h>
#include <string>
bool isSpecial(std::string num){
    for(int i=0; i<num.size(); i++){
        if(i%2==0){
            if(num[i]%2==0) return false;
        }
        else if(num[i]%2!=0) return false;
    }
    return true;
}
int main(){
    int max,min;
    int num;
    scanf("%d",&num);
    for(int i=0; i<num; i++)
        {
        int count=0;
        scanf("%d %d",&min,&max);
        for(int j=min; j<=max; j++){
            std::string numstr=std::to_string(j);
            if(isSpecial(numstr)){
                count++;
            }
        }
        printf("%d\n",count);
    }
}