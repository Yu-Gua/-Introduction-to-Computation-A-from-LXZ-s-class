/*题目 迭代法求平方根
来源：zhouwl改编自chg[ 下一题 ]
  [ 提交程序 ]   [ IDE ]   [ 提交记录 ]
题目描述
根据级数运算，一个数的平方根能用如下公式表示：
sqrt(a) = lim f(n)
          n->∞
其中，f(n) 是一个递推函数，其递推式如下：f(n+1)= 0.5*(f(n)+a/f(n))
显然，迭代的次数越多，求出的值就越精确。
对于一个给定的实数 a，请用上述方法求出它的平方根。
要求前后两次迭代出的 f(n) 的差的绝对值小于等于 1E-5 方可终止

关于输入
一个正实数a

关于输出
一个正实数，它的值是a的平方根，要求精确到小数点后7位

例子输入
4
例子输出
2.0000000
提示信息
请使用双精度浮点数类型，迭代的初始条件请选择f(0)=1
你的计算结果与直接调用sqrt()函数得到的结果可能会不一样
【不许直接调用sqrt()函数！！！】

*/
#include <stdio.h>
#include <algorithm>
#include <cmath>
double sqrt(double a,double last){
    double next=0.5*(last+a/last);
    if(fabs(last-next)<= 1e-5){
        return next;
    }
    else{
        return sqrt(a,next);
    }
}
int main(){
    double a;
    scanf("%lf",&a);
    
    printf("%.7lf",sqrt(a,1));
}