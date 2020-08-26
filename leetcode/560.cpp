/// 和为k的子数组个数

/// merge算法偶尔确实能过，但是NlogN有点慢
/// 前缀和+hash可以做到O(N)
/// 前缀和Pred(i)就是SubArrary(0,i+1)的和
/// 建一个哈希表，key是和，value是这样的前缀的个数
/// 是采用迭代的方式实现的，思想是先计算以i结尾的子数组中有几个和等于k的，再计算以i+1结尾。。。
/// 以j开头i结尾的子数组和为Pred(i)-Pred(j-1),j<i
/// 注意每一步迭代的时候哈希表中的记录只包含i之前的子数组
/// 所以以i结尾的子数组和为k的数目就是哈希表中k-Pred(i)的value

#include <iostream>
#include <queue>
#include <vector>

using namespace std;

class Solution {
private:
    int _subarrarySum(vector<int> &nums, int l, int h, int k) {
        if (l > h) {
            return 0;
        }
        if (l == h) {
            return nums[l] == k ? 1 : 0;
        }
        int mid = (l + h) / 2;
        int ret =
            _subarrarySum(nums, l, mid, k) + _subarrarySum(nums, mid + 1, h, k);
        int left_sum = 0;
        for (int i = mid; i >= l; --i) {
            left_sum += nums[i];
            int right_sum = 0;
            for (int j = mid + 1; j <= h; ++j) {
                right_sum += nums[j];
                if (left_sum + right_sum == k) {
                    ret++;
                }
            }
        }
        return ret;
    }

public:
    int subarraySum(vector<int> &nums, int k) {
        return _subarrarySum(nums, 0, nums.size() - 1, k);
    }
};

int main(void) {

    Solution s;
    vector<int> v = {1, 1, 1};

    cout << s.subarraySum(v, 2) << endl;

    return 0;
}