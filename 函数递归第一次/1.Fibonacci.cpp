/*题目 1063 菲波那契数列
来源：[ 下一题 ]
  [ 提交程序 ]   [ IDE ]   [ 提交记录 ]
题目描述
菲波那契数列是指这样的数列: 数列的第一个和第二个数都为1，接下来每个数都等于前面2个数之和。
给出一个正整数a，要求菲波那契数列中第a个数是多少。

关于输入
第1行是测试数据的组数n，后面跟着n行输入。每组测试数据占1行，包括一个正整数a(1 <= a <= 20)

关于输出
n行，每行输出对应一个输入。输出应是一个正整数，为菲波那契数列中第a个数的大小

例子输入
4
5
2
19
1
例子输出
5
1
4181
1
提示信息
*/
#include <stdio.h>
int fib(int& n){
    printf("current n=%d\n",n);
    if(n<=2){
        return 1;
    }
    else{
        int minus1=n-1;
        int minus2=n-2;
        return (fib(minus1)+fib(minus2));
    }
    
}
int main(){
    int n;
    scanf("%d",&n);
    for(int i=0; i<n; i++){
        int t;
        scanf("%d",&t);
        printf("%d\n",fib(t));
    }
    return 0;
}