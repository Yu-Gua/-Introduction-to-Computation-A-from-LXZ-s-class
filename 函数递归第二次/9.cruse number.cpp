#include <stdio.h>
#include <iostream>
#include <string>
int stringToNum(std::string str){
    int num=0; 
    for(int i=0; i<str.size(); i++){
        num=num*10+(str[i]-'0');
        //按幂展开
    }
    return num;
}
std::string numToString(int num){
    std::string str;
    while(num!=0){
        int digit=num%10;
        char c=digit+'0';
        str=c+str;
        //把从后往前拆出来的每一位加到新字符串的前面
        num/=10;
    }
    return str;
}
int reverse(int num){
    std::string str=numToString(num);
    std::string reverseSt=str;
    for(int i=0; i<str.size(); i++){
        reverseSt[i]=str[str.size()-1-i];
    }
    //反转
    int reNum=stringToNum(reverseSt);
    return reNum;
}
bool check(int num){
    int sum=num+reverse(num);
    std::string sumStr=numToString(sum);
    int half=sumStr.size()/2;
    for(int i=0; i<half; i++){
        if(sumStr[i]!=sumStr[sumStr.size()-i-1]){
            return false;
        }
    }
    return true;
}
int main(){
    int num;
    scanf("%d",&num);
    for(int i=0; i<7; i++){
        int re=reverse(num);
        printf("%d+%d=%d\n",num,re,num+re);
        if(check(num)){
            printf("Y");
            return 0;
        }
        num=num+re;
    }
    printf("N");
}