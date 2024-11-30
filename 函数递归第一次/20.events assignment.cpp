#include <stdio.h>
#include <algorithm>
const int M=1e6;
int time[M]={0};
int main(){
    int n;
    scanf("%d",&n);
    for(int i=0; i<n; i++){
        
        int st,ed;
        scanf("%d %d",&st,&ed);
        time[st]=1;
        time[ed]=1;
        for(int i=st+1; i<ed; i++){
            if(time[i]!=0){
                break;
            }
        }
    }
}