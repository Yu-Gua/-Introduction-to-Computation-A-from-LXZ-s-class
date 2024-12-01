#include <stdio.h>
#include <string>
#include <vector>
#include <algorithm>
const int lim=100;
int a[lim],b[lim];
int asize,bsize;
void read(){
    
    scanf("%d %d",&asize,&bsize);
    for(int i=0; i<asize;i ++){
        scanf("%d",&a[i]);
    }
    for(int i=0; i<bsize; i++){
        scanf("%d",&b[i]);
    }
}
void sort(){
    std::sort(a,a+asize);
    std::sort(b,b+bsize);
}
void combine(){
    for(int i=0; i<bsize; i++){
        a[asize+i]=b[i];
    }
}
void print(){
    for(int i=0; i<asize+bsize; i++){
        if(i){
            printf(" ");
        }
        printf("%d",a[i]);
    }
}
int main(){
    read();
    sort();
    combine();
    print();
}