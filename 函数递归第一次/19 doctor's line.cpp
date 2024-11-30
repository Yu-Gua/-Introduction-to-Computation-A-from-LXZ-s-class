#include <stdio.h>
#include <algorithm>
int main(){
    int N;
    scanf("%d",&N);
    int min;
    int name;
    for(int i=0; i<N; i++){
        if(i==0){
            scanf("%d",&min);
            name=1;
        }
        else{
            int tmp;
            scanf("%d",&tmp);
            if(tmp<min){
                min=tmp;
                name=i+1;
            }
        }
    }
    printf("%d",name);
}