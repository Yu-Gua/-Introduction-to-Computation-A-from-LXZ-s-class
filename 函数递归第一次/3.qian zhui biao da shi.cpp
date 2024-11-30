/*题目 习题(15-1) 前缀表达式 (1010)
来源：计算概论05[ 下一题 ]
  [ 提交程序 ]   [ IDE ]   [ 提交记录 ]
题目描述
前缀表达式是一种把运算符前置的算术表达式，例如普通的表达式2 + 3的前缀表示法为+ 2 3。
前缀表达式的优点是运算符之间不必有优先级关系，也不必用括号改变运算次序，例如(2 + 3) * 4
的前缀表示法为* + 2 3 4。本题求解前缀表达式的值，其中运算符包括+ - * /四个。

关于输入
输入为一行，其中运算符和运算数之间都用空格分隔，运算数是浮点数。

关于输出
输出为一行，表达式的值。
可直接用printf("%f\n", v)输出表达式的值v。

例子输入
* + 11.0 12.0 + 24.0 35.0
例子输出
1357.000000
提示信息
可使用atof(str)把字符串转换为一个double类型的浮点数。atof定义在stdlib.h中。
此题可使用函数递归调用的方法求解。

*/
#include <stdio.h>

#include <iostream>
#include <string.h>
double poland(){
  std::string st;
  std::cin>>st;
  //每次从输入流中读进一个单元
  if(st=="*"){
    return poland()*poland();
  }
  if(st=="+"){
    return poland()+poland();
  }
  if(st=="-"){
    return poland()-poland();
  }
  if(st=="/"){
    return poland()/poland();
  }
  //如果是运算符 就留出运算空间并待定
  double num=std::stod(st);
  return num;
  //如果不是运算符 就是数字 返回数字使其进入运算的空间
}
int main(){
  printf("%f",poland());
}