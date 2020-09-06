#include <iostream>
#include <vector>

using namespace std;

static void _qsort(vector<int> &arr, int left, int right, bool (*pred)(const int, const int)) {
    if (left >= right) {
        // 也许可以在范围比较小的时候使用插入排序
        return;
    }
    int pivot = arr[right]; // 可以使用三选一的方式减少worst case概率
    int i = left - 1;
    for (int j = left; j < right; ++j) {
        // 循环不变量是i是less部分的末尾
        if (pred(arr[j], pivot)) {
            i = i + 1;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[right]);

    // divide and conquer
    _qsort(arr, left, i, pred);
    _qsort(arr, i + 2, right, pred);
}

/// <summary>
/// 快速排序
/// </summary>
/// <param name="arr"></param>
/// <param name="pred"></param>
void sort(vector<int> &arr, bool (*pred)(const int, const int)) { _qsort(arr, 0, arr.size() - 1, pred); }

/// <summary>
/// 洗牌算法，每次从未处理的数字中随机取出一个，放在数组尾部，尾部是已被处理的数字
/// 出现在最末尾的概率 = 1 / n；
/// 出现在次末尾的概率 = (n - 1) / n * 1 / (n - 1) = 1 / n
/// 出现在i末尾的概率 = (n - 1) / n * ... * (n - i) / (n - i + 1) * 1 / (n - i) = 1 / n
/// </summary>
/// <param name="arr"></param>
void shuffle(vector<int> &arr) {
    // srand((unsigned)time(NULL));
    // 注意是从后往前扫描的，不适合online的打散。
    for (int i = arr.size() - 1; i >= 0; --i) {
        swap(arr[rand() % (i + 1)], arr[i]);
    }
}

int main(void) {

    vector<int> arr(20);

    for (int i = 0; i < arr.size(); ++i) {
        arr[i] = i - 5;
    }

    shuffle(arr);

    for (auto i : arr) {
        cout << i << ' ';
    }
    cout << endl;

    sort(arr, [](const int a, const int b) -> bool { return a < b; });

    for (auto i : arr) {
        cout << i << ' ';
    }
    cout << endl;

    return 0;
}
