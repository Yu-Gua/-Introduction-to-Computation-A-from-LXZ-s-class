#include <stdio.h>
#include <iostream>
const int N=15;
int size;
struct vector{
    int x;
    int y;
};
void turnvector(vector& a){
    int tmp=a.x;
    a.x=-a.y;
    a.y=tmp;
}
//向量顺时针旋转90°
char turnedMatrix[N][N];
void turnmatrix(char matrix[N][N]){
    int mid=size/2;
    for(int i=0; i<size; i++){
        for(int j=0; j<size; j++){
            vector frommid;
            frommid.x=j-mid;
            frommid.y=i-mid;
            turnvector(frommid);
            turnedMatrix[mid+frommid.y][mid+frommid.x]=matrix[i][j];
        }
    }
}   
//矩阵顺时针旋转90°
bool isSame(char newmatrix[N][N]){
    for(int i=0; i<size; i++){
        for(int j=0; j<size; j++){
            if(newmatrix[i][j]!=turnedMatrix[i][j]){
                return false;
            }
        }
    }
    return true;
}
//判断转换后的矩阵和读入的第二个矩阵是否相同

int main(){
    char matrix[N][N];
    char newmatrix[N][N];
    scanf("%d",&size);
    
    for(int i=0; i<size; i++){
        for(int j=0; j<size; j++){
            std::cin.ignore();
            char c;
            c=std::cin.get();
            matrix[i][j]=c;
        }
    }
    for(int i=0; i<size; i++){
        for(int j=0; j<size; j++){
            std::cin.ignore();
            char c;
            c=std::cin.get();
            newmatrix[i][j]=c;
        }
    }
    turnmatrix(matrix);
    int turn=1;
    for( turn=1; turn<5; turn++){
        char copymatrix[N][N];
        for(int i=0; i<size; i++){
            for(int j=0; j<size; j++){
                copymatrix[i][j]=turnedMatrix[i][j];
            }
        }
        if(isSame(newmatrix)){
            break;
        }
        turnmatrix(copymatrix);
    }
    if(turn==5){
        printf("5");
    }
    else if(turn==1){
        printf("1");
    }
    else if(turn==2){
        printf("3");
    }
    else if(turn==3){
        printf("2");
    }
    else if(turn==4){
        printf("4");
    }
    
}