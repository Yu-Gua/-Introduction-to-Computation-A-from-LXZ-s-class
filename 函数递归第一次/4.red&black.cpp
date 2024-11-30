/*题目 红与黑
来源：Japan 2004 Domestic[ 下一题 ]
  [ 提交程序 ]   [ IDE ]   [ 提交记录 ]
题目描述
有一间长方形的房子，地上铺了红色、黑色两种颜色的正方形瓷砖。
你站在其中一块黑色的瓷砖上，只能向相邻的四块瓷砖中的黑色瓷砖移动。
请写一个程序，计算你总共能够到达多少块黑色的瓷砖。

关于输入
包括多个数据集合。每个数据集合的第一行是两个整数W和H，
分别表示x方向和y方向瓷砖的数量。W和H都不超过20。
在接下来的H行中，每行包括W个字符。每个字符表示一块瓷砖的颜色，规则如下
‘.’：黑色的瓷砖
‘#’：红色的瓷砖
‘@’：黑色的瓷砖，并且你站在这块瓷砖上。
该字符在每个数据集合中仅出现一次
当在一行中读入的是两个零时，表示输入结束。

关于输出
对每个数据集合，分别输出一行，显示你从初始位置出发能到达的瓷砖数(记数时包括初始位置的瓷砖)。

例子输入
6 9
....#.
.....#
......
......
......
......
......
#@...#
.#..#.
11 9
.#.........
.#.#######.
.#.#.....#.
.#.#.###.#.
.#.#..@#.#.
.#.#####.#.
.#.......#.
.#########.
...........
11 6
..#..#..#..
..#..#..#..
..#..#..###
..#..#..#@.
..#..#..#..
..#..#..#..
7 7
..#.#..
..#.#..
###.###
...@...
###.###
..#.#..
..#.#..
0 0
例子输出
45
59
6
13
提示信息*/
#include <stdio.h>
#include <iostream>
#include <string>
#include <sstream>
#include <vector>

bool HaveSearched[100][100];
//重置记忆数组的函数 初始化记忆数组
void initialize(){
    for(int i=0; i<100; i++){
        for(int j=0; j< 100; j++){
            HaveSearched[i][j]=false;
        }
    }
}

void input( std::vector <std::vector <int> >& floor, int& start_x, int& start_y,int& sizex,int& sizey){
    
    for(int i=0; i<sizey; i++){
        std::string line;
        std::getline(std::cin,line);
        std::stringstream flow(line);
        char let;
        std::vector <int> lineInNumber; 
        
        while(flow >> let){
            if(let == '.'){
                lineInNumber.push_back(1);
            }
            if(let == '#'){
                lineInNumber.push_back(0);
            }
            if(let == '@'){
                lineInNumber.push_back(1);
                start_x=lineInNumber.size()-1;
                start_y=i;
            }
        }
        floor.push_back(lineInNumber);
    }
    /*
    for(std::vector<int> line : floor){
        for(int& num : line){
            printf("%d ",num);
        }
        printf("\n");
    }
    printf("%d %d\n",start_y,start_x);
    */
}


int count=0;
void searchAvailable(int start_x, int start_y, std::vector <std:: vector <int> > floor){
    int sizex,sizey;
    sizey=floor.size();
    sizex=floor[0].size();
    //棋盘大小
    if(start_x<0 || start_x>= sizex){
        return;
    }
    if(start_y < 0 || start_y >= sizey){
        return;
    }
    if(floor[start_y][start_x] == 0){
        return;
    }
    if(HaveSearched[start_y][start_x]){
        return;
    }
    //如果超出边界 踩到禁区 或者已经搜索过 都中止这条路径并返回上一节点
    HaveSearched[start_y][start_x]=true;
    //把现在的这块合法地块定为已经搜索
    int movex[4]={1,-1,0,0};
    int movey[4]={0,0,1,-1};
    for(int i=0; i<4; i++){
        int tmpx=start_x+movex[i];
        int tmpy=start_y+movey[i];
        searchAvailable(tmpx,tmpy,floor);
        //向周围四个地块搜索
    }
    count++;
    //走到这里就意味着没有被约束条件淘汰 这是一个合法地块 count++
}
int main(){
    
    
    int sizex,sizey;
    int x,y;
    scanf("%d %d",&sizex,&sizey);
    while(sizex+sizey){
        std::vector<std::vector <int> > floor;
        std::vector<std::vector <int>> HaveSearched;
        std::vector <std::vector <int> > searchedline();
        std::cin.ignore();
        input(floor,x,y,sizex,sizey);
        searchAvailable(x,y,floor);
        printf("%d\n",count);
        //每一轮进行完之后开始读取下一轮的数据 重置count 初始化记忆数组
        //并在下一轮开始之前检验是否碰到了0,0的结束条件
        scanf("%d %d",&sizex,&sizey);
        count=0;
        initialize();
    }
    return 0;
}