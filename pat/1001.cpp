#include <iostream>

/// 两数加法，并格式化输出，要求输出英文格式数字（加逗号）
/// 注意边界条件就好

void print_format(int* num) {
    if (*num < 1000 && *num > -1000) {
        printf("%d", *num);
        return;
    }
    *num = *num / 1000;
    print_format(num);
    printf(",");
}

int main(void) {
    int a, b;
    scanf("%d %d", &a, &b);
    int sum = a + b;
    print_format(&sum);
    return 0;
}