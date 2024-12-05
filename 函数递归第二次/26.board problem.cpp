#include <stdio.h>
#include <iostream>
#include <algorithm>
const int lim=10;
char board[lim][lim];
int size,num,count=0;
bool isOccupied[lim];//各列被占据的情况，初始化为false
void init(){
    for(int i=0;i<lim; i++){
        for(int j=0; j<lim; j++){
            board[i][j]='.';
        }
        isOccupied[i]=false;
    }
    count=0;
}
bool isValid(int x,int y){
    if(board[y][x]=='.'){
        return false;
    }//不可落子
    if(isOccupied[x]){
        return false;
    }//列重复
    return true;
}
void readBoard(int size){
    for(int i=0; i<size; i++){
        std::cin.ignore();
        for(int j=0; j<size;j++){
            board[i][j]=std::cin.get();
        }
    }
}
void solve(int havePut,int row,int& count){
    if(havePut==num){
        count++;
        return;
    }
    if(row==size && havePut!=num){
        return;
    }
    if((num-havePut)+row>size){
        return;
    }//剪枝
    for(int i=0; i<size; i++){
        if(isValid(i,row)){
            isOccupied[i]=true;
            solve(havePut+1,row+1,count);
            isOccupied[i]=false;
        }
    }
    solve(havePut,row+1,count);
}
int main(){
    
    scanf("%d %d",&size,&num);
    init();
    while(size!=-1&&num!=-1){
        readBoard(size);//读入棋盘
        solve(0,0,count);//深搜落子
        printf("%d\n",count);
        init();//初始化
        scanf("%d %d",&size,&num);//读取下一组数据
    }
}