#include <iostream>
#include <string>
#include <climits>
#include <stdio.h>


int maxProduct(std::string num) {
    int n = num.length();
    int maxProd = INT_MIN;
    
    // 处理负号
    bool isNegative = (num[0] == '-');
    if (isNegative) {
        num = num.substr(1);  // 去掉负号
    }
    n=num.length();
    
    for (int i = 1; i < n - 1; ++i) {
        for (int j = i + 1; j < n; ++j) {
            // 分割成三个部分
            std::string part1 = num.substr(0, i);
            std::string part2 = num.substr(i, j - i);
            std::string part3 = num.substr(j);

            // 转换为整数
            long long a = std::stoi(part1);
            long long b = std::stoi(part2);
            long long c = std::stoi(part3);

            // 如果原数是负数，调整符号
            if (isNegative) {
                a = -a;
            }

            // 计算乘积
            long long prod = a * b * c;

            // 更新最大乘积
            if (prod > maxProd) {
                maxProd = prod;
            }
        }
    }
    
    return maxProd;
}

int main() {
    std::string num;
    std::cin >> num;
    std::cout << maxProduct(num) << std::endl;
    return 0;
}