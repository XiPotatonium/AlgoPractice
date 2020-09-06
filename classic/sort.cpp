#include <iostream>
#include <vector>

using namespace std;

static void _qsort(vector<int> &arr, int left, int right, bool (*pred)(const int, const int)) {
    if (left >= right) {
        // Ҳ������ڷ�Χ�Ƚ�С��ʱ��ʹ�ò�������
        return;
    }
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

    // divide and conquer
    _qsort(arr, left, i, pred);
    _qsort(arr, i + 2, right, pred);
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

    sort(arr, [](const int a, const int b) -> bool { return a < b; });

    for (auto i : arr) {
        cout << i << ' ';
    }
    cout << endl;

    return 0;
}
