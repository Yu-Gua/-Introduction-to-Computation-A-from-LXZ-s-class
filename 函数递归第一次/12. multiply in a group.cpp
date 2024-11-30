/*题目 集合里的乘法
来源：2017医学部计算概论-期末考试-王佩[ 下一题 ]
  [ 提交程序 ]   [ IDE ]   [ 提交记录 ]
题目描述
给定一个目标数T和一个整数集合S，判断是否存在S的一个非空子集，子集中的数相乘的积为T。

关于输入
输入为两行。
第一行为目标数T，和S中的元素个数N，以空格隔开。
第二行为S中的N个元素，以空格隔开。
其中 N <= 16。

关于输出
如果可以，则输出YES，否则输出NO。

例子输入
提供两组例子，分别为：

12 5
1 2 3 4 5

33 5
4 2 8 7 5
例子输出
对应的输出分别为：

YES

NO
提示信息
*/
#include <vector>
#include <stdio.h>
#include <iostream>
#include <string>

bool flag=false;
void mul(std::vector <int> group,int index,int size,std::vector<int>& select,int num,int&product){
    if(flag) return;
    if(index==size) return;
    if(num%product!=0){
        return;
    }
    if(group[index]==0){
        group[index]=1;
    }
    select.push_back(group[index]);
    product*=group[index];
    if(product==num){
        
        flag=true;
        return;
    }
    mul(group,index+1,size,select,num,product);
    select.pop_back();
    product/=group[index];
    mul(group,index+1,size,select,num,product);
    return;
}
int main(){
    int target,size;
    scanf("%d %d",&target,&size);
    int num;
    std::vector <int> group;
    for(int i=0; i<size;i++){
        scanf("%d",&num);
        group.push_back(num);
    }
    std::vector <int> selected;
    int product=1;
    mul(group,0,size,selected,target,product);
    if(!flag){
        printf("NO\n");
    }
    else printf("YES\n");
}