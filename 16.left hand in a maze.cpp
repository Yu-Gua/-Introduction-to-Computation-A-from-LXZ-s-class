#include <string>
#include <sstream>
#include <iostream>
#include <stdio.h>
#include <algorithm>
struct info{
    int x;
    int y;
    //坐标
    int direction;
    //N=0 W=1 S=2 E=3
};
const int N=10000;
info path[N];
int height,width;
const int lim=100;
char board[lim][lim];
int haveSearched[lim][lim];
int targetx,targety;
bool cmp(const info& a, const info& b) {
    return a.x == b.x && a.y == b.y && a.direction == b.direction;
}
int movey[4]={-1,0,1,0};
int movex[4]={0,-1,0,1};
bool invalid(int x,int y){
    return 
    x<0 || x>width ||
    y<0 || y>height ||
    board[y][x]=='#';
    }
//非法判断条件
bool canGet(int step,info current){    
    if(current.x==targetx && current.y==targety){
        return true;
    }
    //终点判断
    if(invalid(current.x,current.y)){
        return false;
    }
    //非法判断
    bool goback=true;
    for(int turn=5; turn>=3; turn--){
        int newd=(current.direction+turn)%4;     
        int newy,newx;
        newy=current.y+movey[newd];
        newx=current.x+movex[newd];
        if(!invalid(newx,newy)){
            current.direction=newd;
            goback=false;
            break;
        }
        //左转>直行>右转 保存第一个合法方向为当前面向
    }
    if(goback){
        current.direction=(current.direction+2)%4;
    }
        if(haveSearched[current.y][current.x]!=0){
        bool find=false;
        for(int i=0; i<step; i++){
            if(cmp(path[i],current)) {
                find= true;
                break;
            }
        }
        if(find) return false;
    }
    //死循环判断
    path[step]=current;
    haveSearched[current.y][current.x]=1;
    info newplace={current.x+movex[current.direction],current.y+movey[current.direction],current.direction};
    return canGet(step+1,newplace);
}
int main(){
    while(std::cin >> height >> width){
        std::cin.ignore();
        info current;
        for(int i=0; i<height; i++){
            for(int j=0; j<width;j++){
                char a;
                scanf("%c",&a);
                board[i][j]=a;
                if(a=='T'){
                    targetx=j;
                    targety=i;
                }
                if(a=='S'){
                    current.y=i;
                    current.x=j;
                }
            }
            std::cin.ignore();
        }
        //std::cin.ignore();
        char dir;
        scanf("%c",&dir);
        std::cin.ignore();
        switch(dir){
            case 'N':
            current.direction=0;
            break;
            case 'W':
            current.direction=1;
            break;
            case 'S':
            current.direction=2;
            break;
            case 'E':
            current.direction=3;
            break;
            default:
            printf("Input Direction Error!\n");
            break;
        }
        if(canGet(0,current)){
            printf("YES\n");
        }
        else printf("NO\n");
        for(int i=0; i<height; i++){
            for(int j=0; j<width;j++){
                board[i][j]=0;
                haveSearched[i][j]=0;
            }
        }
        for(int i=0; i<10000; i++){
            path[i]={0,0,0};
        }
    }    
    return 0;
}