#include <stdio.h>
#include <algorithm>
struct sod{
    int x;
    bool take;
    bool isObserved;
};
const int M=1010;
sod soldiers[M];

void dfs(int num, int R){
    int lasttaker=0;
    for(int i=0; i<num; i++){
        if(!soldiers[i].isObserved){
            for(int j=i; j<num; j++){
                if(j==num-1){
                    soldiers[j].take=true;
                    break;
                }
                if(soldiers[j+1].x-soldiers[i].x<=R){
                    continue;
                }
                soldiers[j].take=true;
                lasttaker=j;
                for(int k=i; k<=j; k++){
                    soldiers[k].isObserved=true;
                }
                for(int k=j; k<num; k++){
                    if(soldiers[k].x-soldiers[j].x<=R){
                        soldiers[k].isObserved=true;
                        continue;
                    }
                    break;
                }
                break;
            }
            
        }
    }
    
}
bool cmp(sod a, sod b){
    if(a.x<b.x){
        return true;
    }
    else return false;
}
int main(){
    int R,num;
    scanf("%d %d",&R,&num);
    while(R!=-1 || num!=-1){
        for (int i = 0; i < M; ++i) {
            soldiers[i] = {0, false, false};
        }
        //重置
        for(int i=0; i<num; i++){
            scanf("%d",&soldiers[i].x);
        }
        std::sort(soldiers,soldiers+num,cmp);
        dfs(num,R);
        int count=0;
        for(int i=0; i<num; i++){
            if(soldiers[i].take){
                count++;
            }
        }
        printf("%d\n",count);
        scanf("%d %d",&R,&num);
    }
}