#include <stdio.h>
const int lim=100;
bool GoRight[lim];
int p,q;
int TargetLayer;
int calculate(int layer){
    int x=1;
    for(int i=layer-1; i>=0; i--){
        if(GoRight[i]){
            x*=2;
        }
        else x=2*x-1;
    }
    int sum=1;
    for(int i=0; i<layer-1; i++){
        sum=sum*2+1;
    }
    sum+=x;
    return sum;
}
//从目标层开始倒退，通过回溯的每一步的左右递归算出序数
void Upward(int p,int q,int layer){
    if(p==1&&q==1){
        TargetLayer=layer;
        return;
    }
    if(p>q){
        GoRight[layer]=true;
        Upward(p-q,q,layer+1);
        return;
    }
    else if(p<q){
        GoRight[layer]=false;
        Upward(p,q-p,layer+1);
        return;
    }
}
//递归记录每一步回溯是向左还是向右
int main(){
    int cases;
    scanf("%d",&cases);
    for(int i=0; i<cases;i++){
        scanf("%d %d",&p,&q);
        Upward(p,q,0);
        printf("%d\n",calculate(TargetLayer));
    }
}