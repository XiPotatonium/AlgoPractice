/// �������е��������֣����ǰ��һ�����ִ��ں�������֣����������������һ������ԡ�����һ�����飬�����������е�����Ե�������
/// �鲢˼�룬�е���������Ӵ���
/// �����������ʵ��Զ��Խ������ܹ���һ����������Ϊ����û�й��ֵĿ�ʱ�䣬�ٷ�����������˳��ʵ�ֹ鲢��������ֱ����sort���е�͵��
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