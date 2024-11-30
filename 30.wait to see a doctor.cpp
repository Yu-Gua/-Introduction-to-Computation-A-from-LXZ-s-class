#include <stdio.h>
#include <algorithm>
const int M=1010;
struct patient{
    int time;
    int name;
};
patient patients[M];
void initialize(){
    for(int i=0; i<M; i++){
        patients[i]={0,0};
    }
}
bool cmp(patient a, patient b){
    return(a.time<b.time);
}
int main(){
    int n;
    double total=0;
    scanf("%d",&n);
    for(int i=0; i<n; i++){
        scanf("%d",&patients[i].time);
        patients[i].name=i+1;
    }
    std::sort(&patients[0],&patients[n],cmp);
    for(int i=0; i<n; i++){
        if(i){
            printf(" ");
        }
        printf("%d",patients[i].name);
        total+=(n-i-1)*patients[i].time;
    }
    printf("\n");
    total/=n;
    printf("%.2lf",total);
}