/*题目 八皇后问题
来源：chg[ 下一题 ]
  [ 提交程序 ]   [ IDE ]   [ 提交记录 ]
题目描述
会下国际象棋的人都很清楚：皇后可以在横、竖、斜线上不限步数地吃掉其他棋子。如何将8个皇后放在棋盘上（有8 * 8个方格），使它们谁也不能被吃掉！即任何两个皇后都不会在同一行、同一列、或同一斜线上。这就是著名的八皇后问题。

关于输入
本题没有输入

关于输出
输出八皇后问题所有的解，解用一个 8*8 的字符方正表示，如果某个位置没有皇后，则对应的字符为“.”，如果有皇后，则对应的字符为“*”。
为了美观起见，同一行的两个字符之间有一个空格，解的前一行是一个数字，表示这个解的序号。
（详见例子输出）解要按照皇后在第 1 列、第 2 列……第 8 列出现的行数从小到大依次排序。

例子输入
（无）
例子输出
1
* . . . . . . .
. . . . . . * .
. . . . * . . .
. . . . . . . *
. * . . . . . .
. . . * . . . .
. . . . . * . .
. . * . . . . .
2
* . . . . . . .
. . . . . . * .
. . . * . . . .
. . . . . * . .
. . . . . . . *
. * . . . . . .
. . . . * . . .
. . * . . . . .

………………

92
. . * . . . . .
. . . . . * . .
. . . * . . . .
. * . . . . . .
. . . . . . . *
. . . . * . . .
. . . . . . * .
* . . . . . . .
提示信息*/

#include <stdio.h>
#include <vector>
#include <algorithm>
#include <string>

//把皇后位置print的函数
//调用的参数是queen数组 表达皇后在每一列中的位置索引
void output(std::vector<int>& queen){
    for(int i=0; i<8 ; i++){
        int queenPlaceInLine=std::find(queen.begin(),queen.end(),i)-queen.begin();
        //找到i行中皇后的索引
        for(int j=0; j<8; j++){
            if(j>0){
                printf(" ");
            }
            if(j == queenPlaceInLine){
                printf("*");
            }
            else{
                printf(".");
            }
        }
        printf("\n");
    }
}

//递归寻找皇后位置的函数
bool checksafe(std::vector <std::vector <int> > board ,int x, int y){
    
    std::vector <int> line=board[y];
    if(std::find(line.begin(),line.end(),1)!=line.end()){
        return false;
    }
    //行中找到皇后就否定
    std::vector <int> col;
    for(int i=0; i<8; i++){
        col.push_back(board[i][x]);
    }
    if(std::find(col.begin(),col.end(),1)!=col.end()){
        return false;
    }
    //列中找到皇后就否定
    std::vector <int> diagnol;
    int tmpx=x,tmpy=y;
    while(tmpx>=0 && tmpy>=0){
        diagnol.push_back(board[tmpy][tmpx]);
        tmpy--;
        tmpx--;
    }
    tmpx=x,tmpy=y;
    while(tmpx<8 && tmpy < 8){
        diagnol.push_back(board[tmpy][tmpx]);
        tmpy++;
        tmpx++;
    }
    tmpx=x,tmpy=y;
    while(tmpx<8 && tmpy >= 0){
        diagnol.push_back(board[tmpy][tmpx]);
        tmpy--;
        tmpx++;
    }
    tmpx=x,tmpy=y;
    while(tmpx>=0 && tmpy < 8){
        diagnol.push_back(board[tmpy][tmpx]);
        tmpy++;
        tmpx--;
    }
    if(std::find(diagnol.begin(),diagnol.end(),1)!=diagnol.end()){
        return false;
    }
    return true;
    //对角线找到皇后就否定
}

void FindQueen(std::vector <std::vector<int>>& board,int lineNum,std::vector<int>& queen,int&count){
    if(lineNum==8){
        count++;
        printf("%d\n",count);
        output(queen);
        return;
    }
    //如果一路走到尽头，那么原地输出结果
    for(int placeInCol=0; placeInCol<8; placeInCol++){
        if(checksafe(board,lineNum,placeInCol)){
            board[placeInCol][lineNum]=1;
            queen.push_back(placeInCol);
            //如果可以放置 就在当前位置放置皇后并填入记录数组
            FindQueen(board,lineNum+1,queen,count);
            //尝试对下一列寻找
            //如果下一列全都没有找到可能位置就会返回这里
            board[placeInCol][lineNum]=0;
            queen.pop_back();
            //如果下一列全部堵死了，就在这里回溯，把刚才放置的皇后提走
        }
    }
}
int main(){
    std::vector <int> zeroLine(8,0);
    std::vector <std::vector <int>> board;
    for(int i=0; i<8;i ++){
        board.push_back(zeroLine);
    }
    //初始化棋盘
    std::vector <int> queen;
    int count=0;
    FindQueen(board,0,queen,count);
}