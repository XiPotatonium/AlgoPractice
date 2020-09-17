#include <iostream>
#include <vector>

using namespace std;

/// <summary>
/// 每一轮选最小的那个
/// </summary>
/// <param name="arr"></param>
/// <param name="pred"></param>
static void _selection(vector<int> &arr, bool (*pred)(const int, const int)) {
    for (int i = 0; i < arr.size() - 1; ++i) {
        int min_idx = i;
        for (int j = i + 1; j < arr.size(); ++j) {
            if (pred(arr[j], arr[min_idx])) {
                min_idx = j;
            }
        }
        swap(arr[i], arr[min_idx]);
    }
}

/// <summary>
/// 扑克牌，将未排序的第一个插入排序部分
/// </summary>
/// <param name="arr"></param>
/// <param name="pred"></param>
static void _insertion(vector<int> &arr, bool (*pred)(const int, const int)) {
    for (int i = 0; i < arr.size() - 1; ++i) {
        int j = i + 1;
        int tmp = arr[j];
        for (; j > 0; --j) {
            if (pred(tmp, arr[j - 1])) {
                arr[j] = arr[j - 1];
            } else {
                break;
            }
        }
        arr[j] = tmp;
    }
}

static void _bubble(vector<int> &arr, bool (*pred)(const int, const int)) {
    for (int i = 0; i < arr.size() - 1; ++i) {
        for (int j = 0; j < arr.size() - i - 1; ++j) {
            if (pred(arr[j + 1], arr[j])) {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

static int _partition(vector<int> &arr, int left, int right, bool (*pred)(const int, const int)) {
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
    return i + 1;
}

static void _qsort(vector<int> &arr, int left, int right, bool (*pred)(const int, const int)) {
    if (left >= right) {
        // 也许可以在范围比较小的时候使用插入排序
        return;
    }

    int mid = _partition(arr, left, right, pred);

    // divide and conquer
    _qsort(arr, left, mid - 1, pred);
    _qsort(arr, mid + 1, right, pred);
}

static void qsort_iter(vector<int> &arr, bool (*pred)(const int, const int)) {
    vector<pair<int, int>> stack;
    int left = 0, right = arr.size() - 1;
    while (right > left || !stack.empty()) {
        if (right > left) {
            int mid = _partition(arr, left, right, pred);
            stack.push_back(make_pair(mid + 1, right));
            right = mid - 1;
        } else {
            left = stack.back().first;
            right = stack.back().second;
            stack.pop_back();
        }
    }
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

    cout << "Quick Sort:" << endl;
    sort(arr, [](const int a, const int b) -> bool { return a < b; });

    for (auto i : arr) {
        cout << i << ' ';
    }
    cout << endl << endl;

    shuffle(arr);

    for (auto i : arr) {
        cout << i << ' ';
    }
    cout << endl;

    cout << "Quick-Iter Sort:" << endl;
    qsort_iter(arr, [](const int a, const int b) -> bool { return a < b; });

    for (auto i : arr) {
        cout << i << ' ';
    }
    cout << endl << endl;

    shuffle(arr);

    for (auto i : arr) {
        cout << i << ' ';
    }
    cout << endl;

    cout << "Bubble Sort:" << endl;
    _bubble(arr, [](const int a, const int b) -> bool { return a < b; });

    for (auto i : arr) {
        cout << i << ' ';
    }
    cout << endl << endl;

    shuffle(arr);

    for (auto i : arr) {
        cout << i << ' ';
    }
    cout << endl;

    cout << "Insertion Sort:" << endl;
    _insertion(arr, [](const int a, const int b) -> bool { return a < b; });

    for (auto i : arr) {
        cout << i << ' ';
    }
    cout << endl << endl;

    shuffle(arr);

    for (auto i : arr) {
        cout << i << ' ';
    }
    cout << endl;

    cout << "Selection Sort:" << endl;
    _selection(arr, [](const int a, const int b) -> bool { return a < b; });

    for (auto i : arr) {
        cout << i << ' ';
    }
    cout << endl << endl;

    return 0;
}
