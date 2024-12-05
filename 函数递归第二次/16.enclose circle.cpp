#include <stdio.h>
#include <algorithm>
#include <cmath>
bool isCrossed(int x1,int y1,int r1,int x2,int y2,int r2){
    int RSqr=(r1+r2)*(r1+r2);
    int disSqr=(x1-x2)*(x1-x2)+(y1-y2)*(y1-y2);
    return RSqr>disSqr;
}
//避免使用sqrt，提高运行效率
const int lim=1010;
struct cir{
    int x;
    int y;
    int r;
};
cir circles[lim];
bool cmp(cir c1,cir c2){
    return c1.r>c2.r;
}
int main(){
    int num;
    scanf("%d",&num);
    for(int i=0; i<num; i++){
        scanf("%d %d %d",&circles[i].x,&circles[i].y,&circles[i].r);
    }
    bool flag=false;
    std::sort(circles,circles+num,cmp);
    //按照半径大小降序排列
    //这样先搜索比较大的圆，更容易早一点找到相交
    for(int i=0; i<num-1; i++){
        for(int j=i+1; j<num; j++){
            if(isCrossed(circles[i].x,circles[i].y,circles[i].r,circles[j].x,circles[j].y,circles[j].r)) flag=true;
            break;
        }
        if(flag) break;
    }
    if(flag){
        printf("Yes");
    }
    else printf("No");
}