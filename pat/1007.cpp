/// 算法导论中的那个方法并不是最优的，他只是为了演示分治


#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int max_sum;
    int start_idx;
    int end_idx;

    void solve(vector<int> &arr) {
        max_sum = INT32_MIN;
        int sum = 0, cur_start = 0;
        for (int i = 0; i < arr.size(); ++i) {
            sum += arr[i];
            if (sum > max_sum) {
                max_sum = sum;
                start_idx = cur_start;
                end_idx = i;
            }
            if (sum < 0) {
                sum = 0;
                cur_start = i + 1;
            }
        }
    }
};

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);

    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    Solution s;
    s.solve(arr);
    if (s.max_sum < 0) {
        printf("0 %d %d", arr[0], arr[arr.size() - 1]);
    } else {
        printf("%d %d %d", s.max_sum, arr[s.start_idx], arr[s.end_idx]);
    }

    return 0;
}
