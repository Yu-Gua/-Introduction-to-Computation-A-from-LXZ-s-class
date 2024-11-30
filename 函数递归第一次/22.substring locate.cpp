#include <stdio.h>
#include <string>
#include <iostream>
#include <algorithm>
int main(){
    std::string sub;
    std::string st;
    std::cin >> sub >> st;
    int index=st.find(sub);
    printf("%d",index);
}