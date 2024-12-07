#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

//计算每列的和，读入参数为矩阵、记录每列移动多少的数组
int calculateMaxColumnSum(const vector<vector<int>>& matrix, const vector<int>& shifts) {
    int n = matrix.size();
    vector<int> colSums(n, 0);
    
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            colSums[j] += matrix[i][(j + shifts[i]) % n];
        }
    }
    
    return *max_element(colSums.begin(), colSums.end());
}
//递归生成全部的可能移动方案
//每一次生成一种所有列的移动方案就压入全部方案集
void generateShifts(int row, int n, vector<int>& currentShifts, vector<vector<int>>& allShifts) {
    if (row == n) {
        allShifts.push_back(currentShifts);
        return;
    }

    for (int shift = 0; shift < n; ++shift) {
        currentShifts[row] = shift;
        generateShifts(row + 1, n, currentShifts, allShifts);
    }
}

int main() {
    while (true) {
        int n;
        cin >> n;
        if (n == -1) break;

        vector<vector<int>> matrix(n, vector<int>(n));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                cin >> matrix[i][j];
            }
        }

        vector<int> currentShifts(n, 0);
        //初始化为所有列都不移动
        vector<vector<int>> allShifts;
        generateShifts(0, n, currentShifts, allShifts);
        //生成所有移动方案存入方案集

        int minMaxSum = INT_MAX;
        for (const auto& shifts : allShifts) {
            minMaxSum = min(minMaxSum, calculateMaxColumnSum(matrix, shifts));
        }
        //遍历所有移动方案计算列极大值的最小值

        cout << minMaxSum << endl;
    }

    return 0;
}