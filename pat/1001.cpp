#include <iostream>

/// �����ӷ�������ʽ�������Ҫ�����Ӣ�ĸ�ʽ���֣��Ӷ��ţ�
/// ע��߽������ͺ�

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