#include <string>
#include <iostream>
#include <stdio.h>
std::string origin;
std::string sub1;
std::string sub2;
bool flag=false;
int lastfind=0;
void search( char* starttwo, char* endtwo){
    if(origin.find(sub2,starttwo-&origin[0]+1)!=std::string::npos)
    {   char* newstart=&origin[origin.find(sub2,starttwo-&origin[0]+1)];
        char* newend=newstart+sub2.size()-1;
        lastfind=newstart-&origin[0];
        search(newstart,newend);
    }
    else return;
    
}
int main(){
    std::getline(std::cin,origin,',');
    std::getline(std::cin,sub1,',');
    std::getline(std::cin,sub2);
    char *startone=nullptr,*endone=nullptr;
    char *endtwo=nullptr,*starttwo=nullptr;

    if( origin.find(sub2)!=std::string::npos && origin.find(sub2)>origin.find(sub1)){
        startone=&origin[origin.find(sub1)];
        endone=startone+sub1.size()-1;
        starttwo=&origin[origin.find(sub2)];
        endtwo=starttwo+sub2.size()-1;
        lastfind=starttwo-&origin[0];
        search(starttwo,endtwo);
        if(lastfind>(endone-&origin[0])){
            printf("%d",-1+lastfind-(endone-&origin[0]));
        }
        else{
            printf("-1");
        }
    }
    else {
        printf("-1");
    }
}