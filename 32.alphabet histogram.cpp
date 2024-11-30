#include <stdio.h>
#include <iostream>
#include <string>
#include <algorithm>
const int letters=26;
int frequency[26]={0};
void print(int max,int layer){
    if(layer==max-1){
        printf("#");
        for(int j=0; j<letters; j++){
            int checkempty=0;
            for( checkempty=j; checkempty<letters; checkempty++){
                if(frequency[checkempty]<=0) continue;
                
                else break;
            }
            if(checkempty==letters){
                printf("\n");
                break;
            }
            printf(" ");
            if(frequency[j]>0){
                printf("*");
            }
            else{
                printf(" ");
            }
        }
        printf("\n");
        return;
    }
    for(int j=0; j<letters; j++){
        frequency[j]--;
    }
    print(max,layer+1);
    for(int j=0; j<letters; j++){
        frequency[j]++;
    }
    printf("#");
        for(int j=0; j<letters; j++){
            int checkempty=0;
            for( checkempty=j; checkempty<letters; checkempty++){
                if(frequency[checkempty]<=0) continue;
                
                else break;
            }
            if(checkempty==letters){
                printf("\n");
                break;
            }
            printf(" ");
            if(frequency[j]>0){
                printf("*");
            }
            else{
                printf(" ");
            }
        }
    printf("\n");
}
int main(){
    while(std::cin){
        char c=std::cin.get();
        if(std::isalpha(c)){
            int index=c-'A';
            frequency[index]++;
        }
    }
    int max=0;
    for(int i=0; i<letters; i++){
        if(frequency[i]>max){
            max=frequency[i];
        }
    }
    print(max,0);
    //printf("\n");
    printf("#");
    for(int i=0; i<letters; i++){
        printf(" %c",'A'+i);
    }
}