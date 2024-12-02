#include <stdio.h>
#include <algorithm>
#include <cmath>
int maxsum=0;//记录最高分数
int startRecord=0;
int time=0;//当前消耗时间(dp)
int timeRecord=0;//记录当前最高分数的最优时间
const int lim=1005;
int timeChart[lim];
int scoreChart[lim];
int questionNum;
int TimeLimit;
int endNum=-1;//上一次加到哪里停止(dp)
int formerSum=0;//上一次的加和(dp)
//通过记录每次从哪里加到哪里，并记录加和值，可以避免重复计算
void planning(){
    int st=0; 
    for(st=0; st<questionNum; st++){
        if(formerSum>0){
            formerSum-=scoreChart[st-1];
            time-=timeChart[st-1];
        }
        //维护，去除上一次的开头的题

        for(int i=std::max(endNum+1,st);i<questionNum ; i++){
            time+=timeChart[i];
            if(time>TimeLimit){
                time-=timeChart[i];
                //超时就回退
                endNum=i-1;
                //记录合法的最后一个加进来的题目
                break;
            }
            if(i==questionNum-1){
                endNum=i;
            }
            //T_T注意！！这个bug硬控我三个小时
            //边界处理：如果i已经走到头了，我内置的超时返回endNum就不会更新endNum
            //导致最后一道题的分数不断累加
            //所以在这里加上i已经到尽头的更新条件
            formerSum+=scoreChart[i];
        }
        if (formerSum>maxsum){
            maxsum=formerSum;
            timeRecord=time;
            startRecord=st;
        }
        else if(formerSum==maxsum && time<timeRecord){
            timeRecord=time;
            startRecord=st;
        }
        //如果分数更优或者时间更优，更新记录
    }
}
int main(){
    scanf("%d %d",&questionNum,&TimeLimit);
    for(int i=0; i<questionNum; i++){
        scanf("%d,%d",&scoreChart[i],&timeChart[i]);
    }
    planning();
    printf("%d:%d;%d",startRecord+1,maxsum,timeRecord);
}