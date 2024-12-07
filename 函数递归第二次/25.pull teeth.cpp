#include <iostream>
#include <vector>
using namespace std;
int dp[50];

// 用记忆化搜索计算总方法数
int countWays(int n) {
    if (n == 0 || n == 1) {
        return 1;
    }
    if (dp[n] != -1) {
        return dp[n];
    }
    //如果该结果已经计算过，直接调用
    dp[n]=countWays(n - 1) + countWays(n - 2);
    return dp[n];
}

int main() {
    int n;
    cin >> n;
    for(int i=0; i<50 ; i++){
        dp[i] = -1;
    }
    //用-1来表示未计算
    // 输出结果
    cout << countWays(n) << endl;

    return 0;
}