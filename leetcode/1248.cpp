/// 计算含有K个奇数的子数组
/// 不适合用动规，可以O(N)

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int numberOfSubarrays(vector<int> &nums, int k) {
        int ret = 0;
        int cur = 0;
        int tail = 0, head = 0;
        for (; tail < nums.size(); ++tail) {
            if (nums[tail] % 2 != 0) {
                ++cur;
            }
            if (cur > k) {
                while (nums[head++] % 2 == 0)
                    ;
                --cur;
            }
            if (cur == k) {
                for (int i = head; nums[i] % 2 == 0; ++i) {
                    ++ret;
                }
                ++ret;
            }
        }
        return ret;
    }
};

int main(void) {
    Solution solution;

    vector<int> nums({1, 1, 2, 1, 1});

    cout << solution.numberOfSubarrays(nums, 3);

    return 0;
}