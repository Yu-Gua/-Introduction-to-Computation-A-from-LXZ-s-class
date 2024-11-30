/*题目 猴子爬山
来源：医学部计算概论[ 下一题 ]
  [ 提交程序 ]   [ IDE ]   [ 提交记录 ]
题目描述
一个小猴子蹦蹦跳跳去爬山。从山下到山顶共有m个台阶(m<=40)。
小猴子很顽皮，有时候一次跳1个台阶，有时候一次跳3个台阶，还有时候一次跳5个台阶。
请问，小猴子上山有多少种不同的跳法。

例如，当m=6时，小猴子有下面8种跳法：
1. 1 1 1 1 1 1
2. 1 1 1 3
3. 1 1 3 1
4. 1 3 1 1
5. 3 1 1 1
6. 3 3
7. 1 5
8. 5 1

关于输入
输入只有1行。其中包含一个数字m，表示从山下到山顶的台阶数。

关于输出
输出只有1行。其中包含一个数字，表示小猴子上山有多少种跳法。

例子输入
6
例子输出
8
提示信息*/
#include <stdio.h>
int ways(int stairs){
    if(stairs<0){
        return 0;
    }
    if(stairs==1){
        return 1;
    }
    if(stairs==3){
        return 2;
    }
    if(stairs==5){
        return 5;
    }
    return ways(stairs-1)+ways(stairs-3)+ways(stairs-5);
}
int main(){
    int stairs;
    scanf("%d",&stairs);
    printf("%d",ways(stairs));
}