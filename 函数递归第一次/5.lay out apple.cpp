/*题目  放苹果
来源：[ 下一题 ]
  [ 提交程序 ]   [ IDE ]   [ 提交记录 ]
题目描述
把M个同样的苹果放在N个同样的盘子里，允许有的盘子空着不放，问共有多少种不同的分法？
（用K表示）5，1，1和1，5，1 是同一种分法。

关于输入
输入：第一行是测试数据的数目t（0 <= t <= 20）。以下每行均包含二个整数M和N，以空格分开。
1<=M，N<=20。

关于输出
输出：对输入的每组数据M和N，用一行输出相应的K。

例子输入
1
7 3
例子输出
8
提示信息*/
#include <vector>
#include <stdio.h>
#include <algorithm>
int way(int apple, int shares){
  if(shares==1){
    return 1;
  }
  //只有一份时 当然只有唯一一种分法
  if(apple<=1){
    return 1;
  }
  //苹果的规模会逐渐缩小到只有1或0 这个时候应该返回基础结果=1
  if(apple<shares){
    return way(apple,apple);
    //苹果小于份数 那么最多占apple个份 这样可以缩小份数的规模
  }
  int emptyOne=way(apple,shares-1);
  //如果有空盘子 那么方案数和shares=shares-1的方案数相同
  int allFilled=way(apple-shares,shares);
  //如果没有空盘子 那么每个盘子至少有一个 去掉这shares个苹果后剩下苹果的方案数就是apple=apple-share
  return emptyOne+allFilled;
  //有没有空盘子是不重不漏的 这两种情形可以直接相加 这样就让apple或者share的规模递减了
}
int main(){
  int N;
  scanf("%d",&N);
  for(int i=0; i<N; i++){
    int apple,shares;
    scanf("%d %d",&apple,&shares);
    printf("%d\n",way(apple,shares));
  }
}