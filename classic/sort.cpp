#include <iostream>
#include <vector>

using namespace std;

/// <summary>
/// ÿһ��ѡ��С���Ǹ�
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
/// �˿��ƣ���δ����ĵ�һ���������򲿷�
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
    int pivot = arr[right]; // ����ʹ����ѡһ�ķ�ʽ����worst case����
    int i = left - 1;
    for (int j = left; j < right; ++j) {
        // ѭ����������i��less���ֵ�ĩβ
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
        // Ҳ������ڷ�Χ�Ƚ�С��ʱ��ʹ�ò�������
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
/// ��������
/// </summary>
/// <param name="arr"></param>
/// <param name="pred"></param>
void sort(vector<int> &arr, bool (*pred)(const int, const int)) { _qsort(arr, 0, arr.size() - 1, pred); }

/// <summary>
/// ϴ���㷨��ÿ�δ�δ��������������ȡ��һ������������β����β�����ѱ����������
/// ��������ĩβ�ĸ��� = 1 / n��
/// �����ڴ�ĩβ�ĸ��� = (n - 1) / n * 1 / (n - 1) = 1 / n
/// ������iĩβ�ĸ��� = (n - 1) / n * ... * (n - i) / (n - i + 1) * 1 / (n - i) = 1 / n
/// </summary>
/// <param name="arr"></param>
void shuffle(vector<int> &arr) {
    // srand((unsigned)time(NULL));
    // ע���ǴӺ���ǰɨ��ģ����ʺ�online�Ĵ�ɢ��
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
