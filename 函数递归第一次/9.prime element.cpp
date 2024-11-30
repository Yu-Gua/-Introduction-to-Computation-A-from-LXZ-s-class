/*题目 1090 分解因数
来源：[ 下一题 ]
  [ 提交程序 ]   [ IDE ]   [ 提交记录 ]
题目描述
给出一个正整数a，要求分解成若干个正整数的乘积，即a = a1 * a2 * a3 * ... * an，
并且1 < a1 <= a2 <= a3 <= ... <= an，问这样的分解的种数有多少。注意到a = a也是一种分解。

关于输入
第1行是测试数据的组数n，后面跟着n行输入。每组测试数据占1行，包括一个正整数a (1 < a < 32768)

关于输出
n行，每行输出对应一个输入。输出应是一个正整数，指明满足要求的分解的种数

例子输入
2
2
20
例子输出
1
4
提示信息*/
#include <stdio.h>
#include <algorithm>
int DividerStartFrom(int from, int num){
    if(from*from<=num && num%from==0){
        int c=0;
        for(int newf=from; newf*newf<=num; newf++){
            if(num%newf==0){
                c+=(DividerStartFrom(newf,num/newf));
            }
            
        }
        c++;
        return c;
    }
    if(from*from<=num && num%from!=0){
        return (DividerStartFrom(from+1,num));
    }
    return 1;
}
int main(){
    int time;
    scanf("%d",&time);
    for(int i=0; i<time; i++)
    {    int n;
        scanf("%d",&n);
        printf("%d\n",DividerStartFrom(2,n));
    }
}