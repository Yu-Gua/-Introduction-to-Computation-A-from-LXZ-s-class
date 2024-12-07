#include <iostream>
#include <stdio.h>
#include <string>
#include <stack>
char man;//表示男孩的字符
char woman;//表示女孩的字符
const char emp='=';//占位符
const int lim=110;
//寻找下一个非占位符字符（可能是男孩也可能是女孩）
int nextButNotEmp(int i,std::string& line){
    int ret=i+1;
    while(line[ret]==emp){
        ret++;
    }
    return ret;
}
void Pair_index(int i,std::string& line){
    int ret=nextButNotEmp(i,line);
    if(line[ret]==woman){
        line[i]=emp;
        line[ret]=emp;
        printf("%d %d\n",i,ret);
        return;
    }
    else {
        while(line[ret]==man){
        Pair_index(ret,line);
        //给下一个男生配对
        ret=nextButNotEmp(i,line);
        //配对离队后，再检查现在是否能直接配对女生了
        //循环处理，直到可以直接配对女生为止
        }
        line[i]=emp;
        line[ret]=emp;
        printf("%d %d\n",i,ret);
        return;
    }
}
int main(){
    std::string line;
    std::getline(std::cin,line);
    man=line[0];
    for(int i=0; i<55; i++){
        if(line[i]!=man){
            woman=line[i];
        }
    }
    //获取男生女生字符
    Pair_index(0,line);
}

//本题的特殊之处在于：题目已经规定了全部可以配对，并且开头的男生和最末尾的女生配对
//所以，只需要不断的对中间夹的部分递归配对，配对的进行离队操作，实时更新
//最终会剩下首尾二人配对即可