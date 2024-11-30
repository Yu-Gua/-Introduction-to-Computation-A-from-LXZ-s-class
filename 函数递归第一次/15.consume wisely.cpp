/*题目 合理消费
来源：计算概论B2020-王昭-肖水生-难[ 下一题 ]
  [ 提交程序 ]   [ IDE ]   [ 提交记录 ]
题目描述
计算概论期终考试结束后，同学B感觉自己得到了解脱。回想起复习期间的艰苦岁月，
B决定去某新开的食堂大吃一顿。

B同学希望今天把饭卡的钱全部花完，以抚慰自己受伤的心灵。

已知B的饭卡里有钱p元，给定食堂物品的价格列表（价格不重复），
请你给出所有可能的恰好把p元花掉的购买选择。

如：p=7, 食堂现有价格为 [3,2,6,7]  的物品，则可能的购买选择有：

[3, 2, 2]

[7]

每种价格的物品可以多次选购。

关于输入
n+1行
第1行有两个整数，分别为物品种类n, 以及B卡里多少钱p。
接下来有n行，每行一个数，为每种物品的价格xi。
满足：3<= n <= 10；2<= p <= 200；2<= xi <=100

关于输出
所有可能的购买选择，每种选择一行，要求不重复。
对于每一种选择，价格的顺序要求按照输入顺序。
每种物品可以多次选购无限制。

如果没有恰好花掉的选择，则输出"NO"。

例子输入
4 7
3
2
6
7
例子输出
3 2 2
7
提示信息*/
#include <stdio.h>
#include <algorithm>
#include <string>
const int N=100;
int prices[N]={0};
int path[N]={0};
bool flag=false;
int step=0;
void fromName(int name,int money,int sum,int items){
    if(name==items){
        return;
    }
    if(sum==money){
        for(int i=0; i<step; i++){
            if(i!=0){
                printf(" ");
            }
            printf("%d",path[i]);
        }
        printf("\n");
        flag=true;
        return;
    }
    if(sum>money){
        return;
    }
    path[step]=prices[name];
    step++;
    fromName(name,money,sum+prices[name],items);
    step--;
    path[step]=0;
    fromName(name+1,money,sum,items);
}
int main(){
    
    int money,items;
    scanf("%d %d",&items,&money);
    
    for(int i=0; i<items;i++){
        scanf("%d",&prices[i]);
    }
    int name=0;
    int sum=0;
    fromName(name,money,sum,items);
    if(!flag){
        printf("NO");
    }
}