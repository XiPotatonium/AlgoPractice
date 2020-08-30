#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main(void) {
    int n;
    cin >> n;
    vector<int> input(n);

    int sum_all = 0;

    for (int i = 0; i < n; ++i) {
        cin >> input[i];
        sum_all += input[i];
    }

    sort(input.begin(), input.end());

    int partition = n / 2;
    int sum1 = 0;

    for (int i = 0; i < partition; ++i) {
        sum1 += input[i];
    }

    printf("%d %d", n - partition * 2, sum_all - sum1 * 2);

    return 0;
}