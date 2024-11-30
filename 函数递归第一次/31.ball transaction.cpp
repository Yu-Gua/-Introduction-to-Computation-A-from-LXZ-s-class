#include <stdio.h>
#include <algorithm>
int people;
int go;
const int N=300020;
int flag=false;
bool array[N];
int path[N]={0};
void game(int current){
    array[0]=true;
    current+=go;
    int step=0;
    while(current!=0){
        array[current]=true;
        path[step]=current;
        current=(current+go)%people;
        
        
        step++;
        //记忆走过的路径
    }
    for(int i=0; i<people; i++){
        if(!array[i]){
            for(int i=0; i<step; i++){
                array[path[i]]=false;
                //重置走过的路径
            }
            return;
        }
    }
    flag=true;
    return;
}
int main(){
    scanf("%d",&people);
    
    go=people/2;
    for(; go>=1; go--){
        
        //printf("%d\n",go);
        
            array[0]=false;
        
        if(flag){
            printf("%d",go+1);
            break;
        }
        if(go==1){
            printf("1");
            break;
        }
        
        game(0);
    }
}