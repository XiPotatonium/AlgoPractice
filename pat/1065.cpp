/// �����ӷ��ͱȽ�A+B>C
/// ע����Ϊֻ�ж���һ��ʽ�ӣ�û�б�Ҫ���ʵ�ִ���������case�ͺ���

#include <iostream>

using namespace std;

int main(void) {
    int n;
    long long int a, b, c;
    bool res = false;

    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%lld %lld %lld", &a, &b, &c);
        if (a > 0 && b > 0) {
            if (a > c || b > c) {
                res = true;
            }
            else {
                b = b - c;
                res = a + b > 0;
            }
        }
        else if (a < 0 && b < 0) {
            if (a < c || b < c) {
                res = false;
            }
            else {
                c = c - b;
                res = a > c;
            }
        }
        else if (a + b > c) {
            res = true;
        }
        else {
            res = false;
        }
        printf("Case #%d: %s\n", i + 1, res ? "true" : "false");
    }

    return 0;
}