#include <stdio.h>
#include <iostream>

bool end(char c){
    if(c>='a'&&c<='z'){
        return true;
    }
    if(c>='A'&&c<='Z'){
        return true;
    }
    return false;
}
//判断输入终止的条件
std::string plusone(std::string basetwo){
    if(basetwo[31]=='0'){
        basetwo[31]='1';
        return basetwo;
    }
    //如果最后一位是0，直接变成1即可
    for(int i=31; i>=0; i--){
        if(basetwo[i]=='1'){
            basetwo[i]='0';
        }
        else{
            basetwo[i]='1';
            break;
        }
    }
    return basetwo;
    //如果最后一位是1，逐步往上进位把所有的1变成0，直到遇到第一个0变成1，结束
}
//十进制转二进制字符串的函数
std::string ten_to_two(int num){
    std::string out;
    while(num>0){
        int mod=num%2;
        num/=2;
        char c=mod+'0';
        out=c+out;
        //模2取余法，倒序输出
    }
    for(int i=out.size();i<32;i++){
        out='0'+out;
    }
    //补全先导0
    return out;
}
int main(){
    std::string line;
    std::getline(std::cin,line);
    while(!end(line[0])){
         if(line=="-2147483648"){
             std::cout << "10000000000000000000000000000000" << std::endl;
             std::getline(std::cin,line);
             continue;
         }
        //绝对值超出int范围的边缘值
        bool isneg=false;
        int num=std::stoi(line);
        if(num<0){
            isneg=true;
        }
        if(isneg){
            num=-1*num;
            //取绝对值
            std::string numstr=ten_to_two(num);
            //std::cout << numstr << std::endl;
            //求二进制
            for(int i=0; i<32; i++){
                if(numstr[i]=='0'){
                    numstr[i]='1';
                }
                else numstr[i]='0';
            }
            //std::cout << numstr << std::endl;
            numstr=plusone(numstr);
            //负数的补码是绝对值的补码取反加一
            std::cout << numstr << std::endl;
        }
        else{
            std::string numstr=ten_to_two(num);
            std::cout << numstr << std::endl;
        }
        std::getline(std::cin,line);
    }
}