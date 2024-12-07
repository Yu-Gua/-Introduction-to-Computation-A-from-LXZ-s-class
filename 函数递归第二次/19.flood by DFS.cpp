#include <stdio.h>
#include <stack>
#include <iostream>
const int lim=210;
int length,width;//地图高和宽
int endx,endy;//指挥部
int map[lim][lim];
int waterNum=0;//放水点个数
bool isVisited[lim][lim];
bool flag=false;//标记

struct dot{
    int x;
    int y;
    int height;
};
dot waterPoint[lim*lim];//放水点情况数组
int movx[4]={0,1,0,-1};
int movy[4]={-1,0,1,0};
//初始化记忆数组
void init(){
    for(int i=0; i<length; i++){
        for(int j=0; j<width; j++){
            isVisited[i][j]=false;
        }
    }
}
//搜索函数的实现逻辑是从终点向各个起点走，遇到高过起点的作为障碍，到达任何一个起点即为成功
//函数传递的参数是向哪个起点走的编号，以及当前点的坐标
bool isValid(int casenum,int x,int y){
    if(map[y][x]>waterPoint[casenum].height){
        return false;
    }
    if(x<0 || x>=width || y<0 || y>=length){
        return false;
    }
    if(isVisited[y][x]){
        return false;
    }
    return true;
}
void dfs(int currentTargetNum,int cu_x,int cu_y){
    
    if(map[cu_y][cu_x]>waterPoint[currentTargetNum].height){
        return;
    }
    //司令部高于水面
    if(flag){
        return;
    }
    //快速返回
    //到达终点
    if(cu_x==waterPoint[currentTargetNum].x && cu_y==waterPoint[currentTargetNum].y ){
        flag=true;
        return;
    }
    //四向尝试，尝试完后返回
    for(int i=0; i<4; i++){
        int newx=cu_x+movx[i];
        int newy=cu_y+movy[i];
        if(isValid(currentTargetNum,newx,newy)){
            isVisited[newy][newx]=true;
            dfs(currentTargetNum,newx,newy);
        }
    }
    return;
}   
int main(){
    int N;
    scanf("%d",&N);
    for(int i=0; i<N; i++){
        
        flag=false;//重置成功与否
        scanf("%d %d",&length,&width);
        for(int i=0; i<length; i++){
            for(int j=0; j<width; j++){
                scanf("%d",&map[i][j]);
            }
        }
        scanf("%d %d",&endy,&endx);
        endy--;
        endx--;
        
        scanf("%d",&waterNum);
        for(int i=0; i<waterNum;i++){
            scanf("%d %d",&waterPoint[i].y,&waterPoint[i].x);
            waterPoint[i].y--;
            waterPoint[i].x--;
            waterPoint[i].height=map[waterPoint[i].y][waterPoint[i].x];
        }
        //读取全部信息
        init();//初始化访问标记
        for(int i=0; i<waterNum;i++){
            isVisited[endy][endx]=true;
            dfs(i,endx,endy);
            
            if(flag){
                break;
            }
            //有一个成功就直接结束
            init();
        }
        
        if(flag){
            printf("Yes\n");
        }
        else printf("No\n");
    }
}