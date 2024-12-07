#include <iostream>
#include <sstream>
#include <stack>
#include <vector>
#include <limits>
#include <climits>

bool isOperator(const std::string& token) {
    return token == "+" || token == "-" || token == "*" || token == "/";
}

long long evaluatePostfix(const std::string& expression) {
    std::istringstream iss(expression);
    std::stack<long long> stack;
    std::string token;

    while (iss >> token) {
        if (token == "@") {
            continue; // 忽略 @ 符号
        }

        if (!isOperator(token)) {
            // 处理多位数字
            stack.push(std::stoll(token));
        } 
        else{
            long long b = stack.top(); stack.pop();
            long long a = stack.top(); stack.pop();
            //先入栈的先算，所以先取b（后入栈），后取a（先入栈）

            switch (token[0]) {
                case '+': stack.push(a + b); break;
                case '-': stack.push(a - b); break;
                case '*': stack.push(a * b); break;
                case '/':
                    if (b == 0) {
                        return INT_MAX ;// 表示除零错误
                    }
                    stack.push(a / b);
                    break;
            }
        }
    }
    return stack.top();
    //iss全部读完之后，也就是运算结束，返回这里栈中的元素
}

int main() {
    std::string line;
    while (std::getline(std::cin, line)) {
        long long result = evaluatePostfix(line);
        if (result == INT_MAX) {
            std::cout << "NaN" << std::endl;
            //除零错误
        } else {
            std::cout << result << std::endl;
        }
    }
    return 0;
}

//题记 后缀表达式的计算规则是：从前往后读取，遇到数字就入栈，
//遇到运算符就从栈中取出两个数字，计算后再入栈，最后栈顶元素就是结果。
//其中运算的规则是：先入栈的先算，所以先取b（后入栈），后取a（先入栈），在运算中a在b的前面算（比如遇到减法就是a-b）。