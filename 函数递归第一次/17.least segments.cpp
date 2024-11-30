#include <queue>
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <cstring>
#include <iostream>
int height,width;
const int M=200;
char board[M][M];
bool haveSearched[M][M];
int x1,y1;
int x2,y2;
int min=INT_MAX;

struct dot
{
    int x;
    int y; 
    int face;
    int turns;
    //存储xy坐标，面向方向，到达当前节点已经转弯的次数
};
std::queue<dot> toSearch;

void initialize(){
    min=INT_MAX;
    //std::fill(&board[0][0],&board[0][0]+M*M,'X');
    std::fill(&haveSearched[0][0],&haveSearched[0][0]+M*M,false);
}
//face=0123对应上左下右
int movex[4]={0,-1,0,1};
int movey[4]={-1,0,1,0};
bool isValid(int x, int y){
    if(x==x2 && y==y2){
        return true;
    }
    return(x>=0 && x<=width+1 && y>=0 && y<=height+1 && board[y][x]!='X'&&haveSearched[y][x]==false);
}
void bfs(dot current){
    toSearch.push(current);
    bool First=true;
    //这是一个记录当前是不是在起点的变量，一次性的，第一次就更新为false
    while(!toSearch.empty())
    {    
        
        current=toSearch.front();
        toSearch.pop();
        //把当前访问的出列
        haveSearched[current.y][current.x]=true;
        //已经搜索过标记不再访问
        if(current.turns+1>min){
            continue;
        }
        //剪枝
        if(current.x==x2 && current.y==y2){
            min=std::min(current.turns+1,min);
            //转向数+1等于线段数
            continue;
        }
        //成功的情形
        for(int i=0; i<4; i++){
            //i表示向左转的次数
            dot newp;
            int faceto=(current.face+i)%4;
            newp.x=current.x+movex[faceto];
            newp.y=current.y+movey[faceto];
            newp.face=faceto;
            if(isValid(newp.x,newp.y)){
                
                //如果新搜到的点合法 就加入待搜索队列
                if(i!=0 && !First){
                    newp.turns=current.turns+1;
                    //发生了转向
                    //在起点的时候发生的转向不会增加线段数，应当忽略
                }
                else newp.turns=current.turns;
                toSearch.push(newp);
            }
        }
        First=false;
    }
}
int main(){
    scanf("%d %d",&width,&height);
    int tableNum=0;
    while(height!=0 && width!=0){
        printf("Board #%d:\n",tableNum+1);
        initialize();
        std::fill(&board[0][0],&board[0][0]+M*M,'X');
        //初始化
        std::cin.ignore();
        //忽略换行符 
        for(int i=0; i<height;i++){
            for(int j=0; j<width; j++){
                char c=std::cin.get();
                board[i+1][j+1]=c;
                //这里的用意是让第一行、第一列留空，作为从矩阵外围通过的通路
            }
            std::cin.ignore();
        }
        for(int i=0; i<=width+1; i++){
            board[0][i]=' ';
            board[height+1][i]=' ';
        }
        for(int i=0; i<=1+height; i++){
            board[i][0]=' ';
            board[i][width+1]=' ';
        }
        //给棋盘四周留一圈通路

        scanf("%d %d %d %d",&x1,&y1,&x2,&y2);  
        int casenum=0;
        while(x1!=0 || x2!=0 || y1!=0 || y2!=0){
            initialize();
            dot start={x1,y1,0,0};
            bfs(start);
            casenum++;
            if(min==INT_MAX){
                printf("Pair %d: impossible.\n",casenum);
                scanf("%d %d %d %d",&x1,&y1,&x2,&y2);
                continue;
            }
            printf("Pair %d: %d segments.\n",casenum,min);
            scanf("%d %d %d %d",&x1,&y1,&x2,&y2);
        }
        tableNum++;
        printf("\n");
        scanf("%d %d",&width,&height);
    }
}