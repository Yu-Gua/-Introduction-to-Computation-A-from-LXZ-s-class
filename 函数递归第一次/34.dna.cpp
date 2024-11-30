#include <stdio.h>
#include <string.h>

#define MAX_CHAIN_LENGTH 256 // 包括末尾的空字符 '\0'

void generate_complementary_chain(const char *input_chain, char *output_chain);

int main() {
    int n;
    char input_chain[MAX_CHAIN_LENGTH];
    char output_chain[MAX_CHAIN_LENGTH];

    // 读取链的数量
    scanf("%d", &n);
    getchar(); // 消耗掉换行符

    // 处理每条碱基链
    for (int i = 0; i < n; i++) {
        fgets(input_chain, MAX_CHAIN_LENGTH, stdin);
        
        // 去掉换行符
        size_t len = strlen(input_chain);
        if (len > 0 && input_chain[len - 1] == '\n') {
            input_chain[len - 1] = '\0';
        }
        
        generate_complementary_chain(input_chain, output_chain);

        printf("%s\n", output_chain);
    }

    return 0;
}

// 根据输入链生成互补链
void generate_complementary_chain(const char *input_chain, char *output_chain) {
    for (int i = 0; input_chain[i] != '\0'; i++) {
        switch (input_chain[i]) {
            case 'A':
                output_chain[i] = 'T';
                break;
            case 'T':
                output_chain[i] = 'A';
                break;
            case 'G':
                output_chain[i] = 'C';
                break;
            case 'C':
                output_chain[i] = 'G';
                break;
        }
    }
    output_chain[strlen(input_chain)] = '\0'; // 添加空字符标记字符串结束
}

/*
5
ATATGGATGGTGTTTGGCTCTG
TCTCCGGTTGATT
ATATCTTGCGCTCTTGATTCGCATATTCT
GCGTTTCGTTGCAA
TTAACGCACAACCTAGACTT
*/