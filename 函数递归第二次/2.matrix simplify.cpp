#include <stdio.h>
#include <iostream>
#include <algorithm>
int n;
int matrix[110][110];
int tmpmat[110][110];
int simplify(int size){
    if(size==1){
        return 0;
    }
    //initialize
    for(int i=0; i<size; i++){
        for(int j=0; j<size; j++){
            matrix[i][j]=tmpmat[i][j];
            tmpmat[i][j]=0;
        }
    }
    //row opeartion
    for(int row=0; row<size; row++){
        int rowmin=matrix[row][0];
        for(int j=0; j<size; j++){
            if(matrix[row][j]<rowmin){
                rowmin=matrix[row][j];
            }
            if(rowmin==0){
                break;
            }
            //剪枝
        }
        for(int j=0; j<size; j++){
            matrix[row][j]-=rowmin;
        }
    }
    //column operation
    for(int col=0; col<size; col++){
        int colmin=matrix[0][col];
        for(int j=0; j<size; j++){
            if(matrix[j][col]<colmin){
                colmin=matrix[j][col];
            }
            
            if(colmin==0){
                break;
            }
            //剪枝
        }
        for(int j=0; j<size; j++){
            matrix[j][col]-=colmin;
        }
    }
    int element;
    element=matrix[1][1];
    //fill in tmpmat
    tmpmat[0][0]=matrix[0][0];
    for(int i=2; i<size; i++){
        tmpmat[0][i-1]=matrix[0][i];
        tmpmat[i-1][0]=matrix[i][0];
    }
    //特殊处理第一行第一列
    for(int i=2; i<size; i++){
        for(int j=2; j<size; j++){
            tmpmat[i-1][j-1]=matrix[i][j];
        }
    }
    //从第三行第三列开始的全部填入
    return element+simplify(size-1);
}
int main(){
    scanf("%d",&n);
    while(std::cin){
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                scanf("%d",&tmpmat[i][j]);
            }
        }
        int sum=simplify(n);
        printf("%d\n",sum);
    }
    return 0;
}