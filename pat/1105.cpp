// ÂİĞıÊä³öÒ»¸ö¾ØÕó

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

enum class Direction : int { Right = 0, Down = 1, Left = 2, Up = 3 };

int main(void) {
    int N, m, n;
    cin >> N;

    vector<int> arr(N);

    for (int i = 0; i < N; ++i) {
        cin >> arr[i];
    }

    sort(arr.begin(), arr.end(), greater<int>());

    for (m = 1; m * m < N; ++m)
        ;
    for (;; ++m) {
        if (N % m == 0) {
            n = N / m;
            break;
        }
    }

    Direction direc = Direction::Right;
    int idx = 0, i = 0, j = 0, filled = 0;

    vector<vector<int>> res(m, vector<int>(n));

    while (idx < arr.size() - 1) {
        switch (direc) {
        case Direction::Right:
            for (; j < n - filled - 1; ++j) {
                res[i][j] = arr[idx++];
            }
            break;
        case Direction::Down:
            for (; i < m - filled - 1; ++i) {
                res[i][j] = arr[idx++];
            }
            break;
        case Direction::Left:
            for (; j >= filled + 1; --j) {
                res[i][j] = arr[idx++];
            }
            break;
        case Direction::Up:
            ++filled;
            for (; i >= filled + 1; --i) {
                res[i][j] = arr[idx++];
            }
            break;
        default:
            break;
        }
        direc = static_cast<Direction>((static_cast<int>(direc) + 1) % 4);
    }
    res[i][j] = arr[idx];

    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            if (j != 0) {
                cout << " ";
            }
            cout << res[i][j];
        }
        cout << endl;
    }

    return 0;
}