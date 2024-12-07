#include <stdio.h>
#include <algorithm>
#include <string>
#include <iostream>
int width,height;
const int lim=110;
char map[lim][lim];
bool isvalid(int y,int x){
    return (map[y][x]=='1'&& y>=0 && y<height && x>=0 && x<width);
}
int movex[4]={0,1,0,-1};
int movey[4]={-1,0,1,0};
//从正上方顺时针一圈
int ptnNum=0;
//通扫，扫到图案就开始对该图案用pattern进行精扫
void pattern(int y,int x);
void scan(){
    for(int i=0; i<height; i++){
        for(int j=0; j<width;j++){
            if(map[i][j]=='1'){
                ptnNum++;
                pattern(i,j);
            }
        }
    }
}
//对图案精扫
void pattern(int y,int x){
    map[y][x]='0';
    for(int i=0; i<4;i++){
        if(isvalid(y+movey[i],x+movex[i])){
            pattern(y+movey[i],x+movex[i]);
        }
    }
    //只要该点合法，就把该点标记，并且向四周覆盖
    return;
}
int main(){
    scanf("%d %d",&height,&width);
    for(int i=0; i<height; i++){
        
        for(int j=0; j<width;j++){
            std::cin.ignore();
            map[i][j]=std::cin.get();
        }    
    }

    scan();
    printf("%d",ptnNum);
}