/*题目 1139 棋盘问题
来源：[ 下一题 ]
  [ 提交程序 ]   [ IDE ]   [ 提交记录 ]
题目描述
在一个给定形状的棋盘（形状可能是不规则的）上面摆放棋子，棋子没有区别。
要求摆放时任意的两个棋子不能放在棋盘中的同一行或者同一列
，请编程求解对于给定形状和大小的棋盘，摆放k个棋子的所有可行的摆放方案C。

关于输入
输入含有多组测试数据。
每组数据的第一行是两个正整数，n k，用一个空格隔开，表示了将在一个n*n的矩阵内描述棋盘，以及摆放棋子的数目。 
n <= 8 , k <= n
当为-1 -1时表示输入结束。
随后的n行描述了棋盘的形状：每行有n个字符，其中 # 表示棋盘区域， . 表示空白区域
（数据保证不出现多余的空白行或者空白列）。

关于输出
对于每一组数据，给出一行输出，输出摆放的方案数目C （数据保证C<2^31）。

例子输入
2 1
#.
.#
4 4
...#
..#.
.#..
#...
-1 -1
例子输出
2
1
*/
#include <stdio.h>
#include <iostream>
#include <vector> 
#include <string>
#include <sstream>
#include <algorithm>
void input(std::vector <std::vector <char>>& board,int size){
    for(int i=0; i<size; i++){
        std::string line;
        std::getline(std::cin,line);
        std::stringstream flow(line);
        char alpha;
        std::vector <char> contain;
        while(flow >> alpha){
            contain.push_back(alpha);
        }
        board.push_back(contain);
        //std::cin.ignore();
    }
}
bool isSafe(std::vector <int> placeInLine,int place){
    if(std::find(placeInLine.begin(),placeInLine.end(),place)!=placeInLine.end()){
        return false;
    }
    return true;
}
int countPiece(std::vector <int> placeinline){
    int count=0;
    for(int& place : placeinline){
        if(place != -1) count++;
    }
    return count;
}
void Chess(
        std::vector <std::vector <char> > board, 
        int line,
        int& count,
        std::vector <int>& placeInLine,
        int size,
        int dots)
    {
        /*for(int& place:placeInLine){
            printf("%d ",place);
        }
        printf("\n");*/
        if(countPiece(placeInLine)==dots){
                count++;
                return;
                
            }
            if(line==size ){
            
            return;
        }
        for(int place=0; place<size ; place++){
            if(isSafe(placeInLine,place)&& board[line][place]=='#'){
                placeInLine[line]=place;
                Chess(board,line+1,count,placeInLine,size,dots);
                placeInLine[line]=-1;
            }
        } 
        Chess(board,line+1,count,placeInLine,size,dots);
        return;
}
int main(){
    int size,dots;
    scanf("%d %d",&size,&dots);
    std::cin.ignore();
    while(size!=-1 && dots!=-1){
        std::vector <std::vector <char> > board;
        input(board,size);
        std::vector <int> placeinline(size,-1);
        //用-1表示空 即这行没有棋子
        int line=0;
        int count=0;

        /*
        for(int i=0; i<size; i++){
            for(int j=0; j<size; j++){
                printf("%c ",board[i][j]);
            }
            printf("\n");
        }
        */

        Chess(board,line,count,placeinline,size,dots);
        printf("%d\n",count);
        scanf("%d %d",&size,&dots);
        std::cin.ignore();
    }
}