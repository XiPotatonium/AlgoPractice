#include <iostream>
#include <vector>

using namespace std;

/// <summary>
/// DP解法
/// </summary>
/// <param name="n"></param>
/// <returns></returns>
int foo(int n) {
    vector<double> table = vector<double>(n);
    vector<double> inputs = vector<double>(n);

    double sum = 0;

    for (int i = 0; i < n; ++i) {
        scanf("%f", &inputs[i]);
        table[i] = inputs[i];
        sum += inputs[i];
    }

    for (int i = 0; i < n; ++i) {
        for (int j = n - 1; j > i; --j) {
            table[j] = table[j - 1] + inputs[j];
            sum += table[j];
        }
    }

    printf("%.2f", sum);
}

// 数学解法
int main(void) {
    int n;
    long double x;

    cin >> n;

    long double sum = 0;

    for (int i = 0; i < n; ++i) {
        scanf("%Lf", &x);
        // 注意x放在后面的话会有两个点不过，因为大数情况下(i + 1) * (n - 1)会溢出
        sum += x * (i + 1) * (n - i);
    }

    printf("%.2Lf", sum);

    return 0;
}