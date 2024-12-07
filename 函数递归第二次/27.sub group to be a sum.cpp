#include <stdio.h>
#include <iostream>
const int lim=1000;
int group[lim];
int Target;
int count=0;
int size;
//递归，考虑每个元素是否加入子集并回溯
void sub_group(int i,int& sum){
    if(sum==Target){
        count++;
        return;
    }
    if(i>=size){
        return;
    }
    sum+=group[i];
    sub_group(i+1,sum);
    sum-=group[i];
    sub_group(i+1,sum);
    return;
}
int main(){
    char c =std::cin.get();
    int i=0;
    
    while(c!='\n'){
        group[i]=c-'0';
        c=std::cin.get();
        //读取数字的下一个，要么是空格，要么是换行,要么还是数字
        while(c>='0'&&c<='9'){
            group[i]*=10;
            group[i]+=c-'0';
            c=std::cin.get();
        }
        //还是数字的话，进入循环，按幂加和
        if(c==' '){
            c=std::cin.get();
        }
        //如果是空格，再往后读一个，应该是数字
        i++;
        if(c=='\n'){
            size=i;
        }
        //如果是换行，记录最终的数组大小
    }
    scanf("%d",&Target);
    while(Target!=0){
        int sum=0;
        sub_group(0,sum);
        printf("%d\n",count);
        count=0;
        scanf("%d",&Target);
    }
}