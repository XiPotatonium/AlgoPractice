/// 在数组中的两个数字，如果前面一个数字大于后面的数字，则这两个数字组成一个逆序对。输入一个数组，求出这个数组中的逆序对的总数。
/// 归并思想，有点像最长递增子串。
/// 下面的做法其实相对而言较慢，能过有一定因素是因为判题没有过分的卡时间，官方给的做法是顺便实现归并排序，这里直接用sort了有点偷懒
/// https://leetcode-cn.com/problems/shu-zu-zhong-de-ni-xu-dui-lcof/solution/shu-zu-zhong-de-ni-xu-dui-by-leetcode-solution/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int reversePairs(vector<int> &nums) {
        return inversePairs(nums, 0, nums.size() - 1);
    }

    int inversePairs(vector<int> &nums, int left, int right) {
        if (left >= right) {
            return 0;
        } else if (left + 1 == right) {
            return nums[left] > nums[right] ? 1 : 0;
        }

        int mid = (left + right) / 2;
        int ret =
            inversePairs(nums, left, mid) + inversePairs(nums, mid + 1, right);
        sort(nums.begin() + left, nums.begin() + mid + 1);
        sort(nums.begin() + mid + 1, nums.begin() + right + 1);
        for (int i = mid, j = right; i >= left; --i) {
            while (nums[i] <= nums[j] && j != mid) {
                --j;
            }
            if (j == mid) {
                break;
            } else {
                ret += j - mid;
            }
        }
        return ret;
    }
};

int main(void) {
    Solution solution;

    vector<int> arr = {7, 5, 6, 4};

    cout << solution.reversePairs(arr);

    return 0;
}