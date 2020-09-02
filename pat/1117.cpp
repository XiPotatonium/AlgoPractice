/// 题意有点难理解
/// 思路比较trick
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main(void) {
    int n;
    cin >> n;
    vector<int> dists(n);

    for (int i = 0; i < n; ++i) {
        cin >> dists[i];
    }

    sort(dists.begin(), dists.end(), greater<int>());

    int e;
    for (e = 1; e <= n; ++e) {
        if (dists[e - 1] <= e) {
            break;
        }
    }

    printf("%d\n", e - 1);

    return 0;
}