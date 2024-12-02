#include <stdio.h>
#include <iostream>
#include <string>
//思路（从左向右）
//主函数开始扫描遇到右括号忽略，遇到左括号进入递归
//递归中，遇到左括号进入深一层递归，遇到右括号返回true,遇到最右端返回false
//这样就标记了所有可以配对的括号
//再全部扫一遍，标记所有配对失败的括号即可

std::string line;
const int lim=110;
bool isPaired[lim];
//这个数组记录括号有没有被配对
void initialize(){
    line.clear();
    for(int i=0; i<lim; i++){
        isPaired[i]=false;
    }
}

//搜索参数为发现左括号的索引
bool fromLeft(int index){
    for(int i=index+1; i<=line.size(); i++){
        if(i==line.size()){
            return false;
        }   
        //到达末尾，配对失败
        if(line[i]== '(' ){
            isPaired[i]=fromLeft(i);
        }
        //发现内层括号，继续递归
        if(line[i]== ')' ){
            line[index]='Y';
            line[i]='Y';
            return true;
        }   
        //成功配对并标记这一对括号
    }
    return false;
}
void print(){
    for(int i=0; i<line.size(); i++){
        if(line[i]=='('){
            printf("$");
        }
        else if(line[i]==')'){
            printf("?");
        }
        else printf(" ");
    }
    printf("\n");
}
int main(){
    int cases;
    scanf("%d",&cases);
    std::cin.ignore();
    for(int i=0;i <cases; i++){
        std::getline(std::cin,line);
        std::cout << line << std::endl;
        for(int i=0; i<line.size(); i++){
            if(line[i]=='('){
                isPaired[i]=fromLeft(i);
            }
        }
        print();
        initialize();
    }
}