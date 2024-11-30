/*题目 猴子分苹果
来源：元培-From Whf[ 下一题 ]
  [ 提交程序 ]   [ IDE ]   [ 提交记录 ]
题目描述
有1堆苹果共 m 个，由 n 只猴子按个数平均分配。
每次到达苹果堆放地的猴子只有1只，而且每个猴子都会平均分 1 次苹果。
第1个到达的猴子将苹果平均分成 n 等份，但发现多 k ( k < n )个，
于是，将多余的k个扔掉，然后拿走其中的1等份。
第 2 个猴子同样将剩余的苹果又分成 n 等份，也发现多 k 个，并同样将多余的 k 个扔掉，
然后拿走其中1等份。
之后的每个猴子都这样（将剩余的苹果又分成 n 等份，也发现多 k 个，并将多余的 k 个扔掉，
然后拿走其中1等份）。假设最后的猴子分配后至少可以拿走1个苹果，请根据输入的 n 和 k值，
计算最小的 m

关于输入
输入猴子数目n 和扔掉的个数 k，其中 k 小于 n，n 和 k 之间以空格间隔。

关于输出
输出最小苹果数目

例子输入
2 1
例子输出
7
提示信息
*/
#include <stdio.h>
int apple(int monkeys, int remain){
    int apple=0;
    int i=1;
    
    for(i=1; ; i++){
        bool flag=true;
        apple=i*monkeys+remain;
        
        for(int name=1; name<monkeys; name++){
            if(apple%(monkeys-1) != 0){
                flag=false;
                break;
            }
            apple/=(monkeys-1);
            apple*=monkeys;
            apple+=remain;
            
        }
        if( (apple-remain)%(monkeys)!=0){
            flag=false;
        }
        if(flag==true){
            return apple;
        }
    }
}
int main(){
    int monkeys,remain;
    scanf("%d %d",&monkeys,&remain);
    printf("%d",apple(monkeys,remain));
    return 0;
}