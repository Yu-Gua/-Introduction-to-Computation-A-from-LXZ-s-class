#include <stdio.h>
#include <algorithm>
const int lim=50;
int map[lim][lim];
int stx,sty;
int enx,eny;
int movx[4]={1,0,-1,0};
int movy[4]={0,1,0,-1};
int length,width;
//右下左上
bool isVisited[lim][lim];
bool isValid(int x,int y){
    return x>=0 && x<width && y>=0 && y<length && map[y][x]!=1 && isVisited[y][x]==false ;
}
bool flag=false;
void dfs(int x,int y){
    if(flag) return;
    if(x==enx && y==eny){
        flag=true;
        return;
    }
    for(int i=0; i<4; i++){
        int nx=x+movx[i];
        int ny=y+movy[i];
        if(isValid(nx,ny)){
            isVisited[ny][nx]=true;
            dfs(nx,ny);
        }
    }
}
int main(){
    
    scanf("%d %d",&length,&width);
    for(int i=0; i<length; i++){
        for(int j=0; j<width; j++){
            int tmp;
            scanf("%d",&tmp);
            map[i][j]=tmp;
            if(tmp==2){
                stx=j;
                sty=i;
            }
            if(tmp==3){
                enx=j;
                eny=i;
            }
        }
    }
    dfs(stx,sty);
    if(flag) printf("Yes\n");
    else printf("No\n");
}