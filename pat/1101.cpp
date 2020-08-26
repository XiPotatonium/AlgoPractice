/// 找pivot，其实和quick sort没什么关系，只是作为背景
/// 这里用类似动规的思路，pivot即左起最大值小于本身，右起最小值大于本身即可

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> find_pivot(vector<int> array) {
    vector<int> ret;
    vector<int> max(array.size());
    max[0] = array[0];
    vector<int> min(array.size());
    min[array.size() - 1] = array[array.size() - 1];

    for (int i = 1; i < array.size(); ++i) {
        max[i] = array[i] > max[i - 1] ? array[i] : max[i - 1];
    }
    for (int i = array.size() - 2; i >= 0; --i) {
        min[i] = array[i] < min[i + 1] ? array[i] : min[i + 1];
    }

    for (int i = 0; i < array.size(); ++i) {
        if ((i < array.size() - 1 && min[i + 1] < array[i]) || (i > 0 && max[i - 1] > array[i])) {

        }
        else {
            ret.push_back(array[i]);
        }
    }

    sort(ret.begin(), ret.end());

    return ret;
}

int main(void) {
    vector<int> array;
    int n;
    int v;
    scanf("%d", &n);
    array.reserve(n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &v);
        array.push_back(v);
    }

    vector<int> res = find_pivot(array);
    printf("%d\n", res.size());
    if (res.size() > 0) {
        for (int i = 0; i < res.size() - 1; ++i) {
            printf("%d ", res[i]);
        }
        printf("%d", res[res.size() - 1]);
    }
    printf("\n");
    return 0;
}