/*题目 最佳凑单
来源：2017医学部计算概论-期末考试-蒋逸[ 下一题 ]
  [ 提交程序 ]   [ IDE ]   [ 提交记录 ]
题目描述
消费者为了享受商家发布的满减优惠，常常需要面临凑单问题。

假设有n件商品，每件的价格分别为p1,p2,...,pn，每件商品最多只能买1件。为了享受优惠，需要凑单价为t。
那么我们要找到一种凑单方式，使得凑单价格不小于t（从而享受优惠），同时尽量接近t。被称为“最佳凑单”

如果不存在任何一种凑单方式，使得凑单价格不小于t（即无法享受优惠），那么最佳凑单不存在。

比如当前还差10元享受满减，可选的小件商品有5件，价格分别为3元、5元、8元、8元和9元，每件商品最多只能买1件。
那么当前的最佳凑单就是11元（3元+8元）。

关于输入
第一行输入商品数n（n<=10）和需要凑单价t，如：
5 10
第二行输入每件商品的价格，如：
3 5 8 8 9

关于输出
如果可以凑单成功，则输出最佳凑单的价格，如：
输入
5 10
3 5 8 8 9
输出
11

如果无法凑单成功，则输出0。

如输入
5 10
1 1 1 1 1
则无法凑够10元，输出
0

例子输入
5 10
3 5 8 8 9
例子输出
11
提示信息
1. 为了简化问题，本题中每件商品最多只能买1件。
2. 不同的商品，即使价格相同也可以都买。比如5件商品，价格分别为3元、5元、8元、8元和9元。
你可以买 8元(第3件)+8元(第4件)

*/
#include <stdio.h>
#include <vector>
//判断能否凑到
bool check(std::vector <int> prices,int target){
  int sum=0;
  for(int& p : prices){
    sum+=p;
  }
  if(sum<target){
    return false;
  }
  return true;
}
void FindMin(int target,std::vector <int> prices, int& min,int object,int& sum){
  int num=prices.size();
  if(sum>=target || object==num){
    //触底或者已经凑到就中止
    if(sum<min && sum>=target){
      //更新最优解
      min=sum;
    }
    return;
  }
  else {
    sum+=prices[object];
    FindMin(target,prices,min,object+1,sum);
    //对于object，先选中他，进入下一层递归
    sum-=prices[object];
    FindMin(target,prices,min,object+1,sum);
    //返回后再移除object，考虑没有object的情况，往下进行
    return;
  }
}
int main(){
  std::vector <int> prices;
  int items,target;
  scanf("%d %d",&items,&target);
  for(int i=0; i<items; i++){
    int p;
    scanf("%d",&p);
    prices.push_back(p);
  }
  int all=0;
  for(int& p : prices){
    all+=p;
  }
  int min=all;
  int object=0;
  int sum=0;
  if(check(prices,target)){
    FindMin(target,prices,min,object,sum);
    printf("%d",min);
  }
  else printf("0");
}