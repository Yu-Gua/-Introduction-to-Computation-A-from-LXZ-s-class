#include <stdio.h>
#include <iostream>
#include <string>
#include <algorithm>
int size;
const int N=20;
int movex[4]={0,-1,0,1};
int movey[4]={-1,0,1,0};

//上 左 下 右
char puzzle[N][N];
bool havevisited[N][N];
void initialize(){
    for(int i=0; i<N; i++){
        for(int j=0; j<size; j++){
            puzzle[i][j]='#';
            havevisited[i][j]=false;
        }
    }
}
bool isvalid(int y,int x){
    if(havevisited[y][x]){
        return false;
    }
    if(y>=size || y<0 || x>=size || x<0){
        return false;
    }
    if(puzzle[y][x]=='#'){
        return false;
    }
    return true;
}
bool dfs(int y,int x,int endy,int endx){
    if(!isvalid(y,x)){
        return false;
    }
    havevisited[y][x]=true;
    if(y==endy && x==endx){
        return true;
    }
    
    for(int i=0; i<4; i++){
        if(dfs(y+movey[i],x+movex[i],endy,endx)){
            return true;
        }
    }
    return false;
}
int main(){
    int casenum;
    scanf("%d",&casenum);
    for(int i=0; i<casenum; i++){
        initialize();
        int startx,starty;
        int endx,endy;
        scanf("%d",&size);
        for(int i=0; i<size; i++){
            std::cin.ignore();
            for(int j=0; j<size;j++){
                char c=std::cin.get();
                puzzle[i][j]=c;
                if(c=='s'){
                    startx=j;
                    starty=i;
                }
                if(c=='e'){
                    endx=j;
                    endy=i;
                }
            }
        }
        bool flag=dfs(starty,startx,endy,endx);
        if(flag){
            printf("YES\n");
        }
        else printf("NO\n");
    }
}