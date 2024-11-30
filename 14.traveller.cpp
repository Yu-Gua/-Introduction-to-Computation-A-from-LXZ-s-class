/*题目 旅行售货商问题
来源：chg[ 下一题 ]
  [ 提交程序 ]   [ IDE ]   [ 提交记录 ]
题目描述
一个国家有 n 个城市，每两个城市之间都开设有航班，从城市 i 到城市 j 的航班价格为 cost[i, j] ，
而且往、返航班的价格相同。

售货商要从一个城市出发，途径每个城市 1 次（且每个城市只能经过 1 次），
最终返回出发地，而且他的交通工具只有航班，请求出他旅行的最小开销。

关于输入
输入的第 1 行是一个正整数 n （3 <= n <= 15）
然后有 n 行，每行有 n 个正整数，构成一个 n * n 的矩阵，
矩阵的第 i 行第 j 列为城市 i 到城市 j 的航班价格。

关于输出
输出数据为一个正整数 m，表示旅行售货商的最小开销

例子输入
4
0 4 1 3
4 0 2 1
1 2 0 5
3 1 5 0
例子输出
7
提示信息*/
#include <vector>
#include <stdio.h>
//从current开始走遍所有地方的费用
void fee(std::vector<std::vector<int>> prices,int visitnum,int size,int& cost,
std::vector <int> haveVisited,
int current,
int& min,
const int start){
    if(visitnum==size){
        cost+=prices[current][start];
        if(cost<min){
            min=cost;
        }
        cost-=prices[current][start];
        //递归尽头时比较费用与最小值并更新
        return ;
    }
    if(cost>=min-1){
        return;
    }
    for(int destination=0; destination<size ; destination++){
        if(haveVisited[destination]==0)
        {    haveVisited[destination]=1;
            cost+=prices[current][destination];
            fee(prices,visitnum+1,size,cost,haveVisited,destination,min,start);
            //更新 已拜访城市+1 已拜访状态更新 起点更新为destination
            haveVisited[destination]=0;
            cost-=prices[current][destination];
            //回溯
        }
    }
    
}
int main(){
    int size;
    scanf("%d",&size);
    std::vector <std::vector <int>> prices;
    for(int i=0; i<size; i++){
        std::vector <int> line;
        for(int j=0; j<size; j++){
            int num;
            scanf("%d",&num);
            line.push_back(num);
        }
        prices.push_back(line);
    }
    int min=__INT_MAX__;
    int cost=0;
    int current=0;
    int visitnum=1;
    int start=0;
    
        std::vector <int>haveVisited(size,0);
        haveVisited[start]=1;
        fee(prices,visitnum,size,cost,haveVisited,current,min,start);
    //轮换对称性 从哪里start都一样
    printf("%d",min);
}