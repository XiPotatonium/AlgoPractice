/// 题意有点难理解
/// 思路比较trick

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main(void) {
    vector<int> data;
    int n, x;

    cin >> n;
    data.reserve(n);

    for (int i = 0; i < n; ++i) {
        cin >> x;
        if (x > 0) {
            data.push_back(x);
        }
    }

    sort(data.begin(), data.end());

    int num = 0;
    for (int i = 0; i < data.size(); ++i) {
        if (data[i] == num || data[i] == num + 1) {
            num = data[i];
        } else {
            break;
        }
    }
    printf("%d\n", num + 1);

    return 0;
}