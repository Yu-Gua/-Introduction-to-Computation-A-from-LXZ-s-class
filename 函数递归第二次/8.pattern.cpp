#include <stdio.h>
#include <algorithm>
#include <string>
#include <iostream>
int width,height;
const int lim=200;
char map[lim][lim];
bool isvalid(int y,int x){
    return (map[y][x]=='#'&& y>=0 && y<height && x>=0 && x<width);
}
int movex[8]={0,1,1,1,0,-1,-1,-1};
int movey[8]={-1,-1,0,1,1,1,0,-1};
//从正上方顺时针一圈
int ptnNum=0;
//通扫，扫到图案就开始对该图案用pattern进行精扫
void pattern(int y,int x);
void scan(){
    for(int i=0; i<height; i++){
        for(int j=0; j<width;j++){
            if(map[i][j]=='#'){
                ptnNum++;
                pattern(i,j);
            }
        }
    }
}
//对图案精扫
void pattern(int y,int x){
    map[y][x]='-';
    for(int i=0; i<8;i++){
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
        std::cin.ignore();
        for(int j=0; j<width;j++){
            map[i][j]=std::cin.get();
        }    
    }
    // for(int i=0; i<height; i++){
    //     for(int j=0; j<width; j++){
    //         printf("%c",map[i][j]);
    //     }
    //     printf("\n");
    // }
    scan();
    printf("%d",ptnNum);
}