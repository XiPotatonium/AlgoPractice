/// 一个数组中有两个数只出现了一次，其他数出现了两次，找出这两个数，要求时间O(N)，空间O(1)
/// 空间O(1)，很明显是用异或的
/// 一个很妙的思路。将所有数分类到哦两个桶中（有点哈希的感觉），要求：
/// 1. 同样的数在同样的桶。（必然是通过位pattern来分类）
/// 2. 两个只出现了一次的数在不同的桶。（第一轮异或的结果可以给我们提供这两个数在哪些位上会有差异）

#include <iostream>
#include <queue>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> singleNumbers(vector<int> &nums) {
        vector<int> ret(2);
        int sum = 0;
        for (vector<int>::iterator iter = nums.begin(); iter != nums.end();
             ++iter) {
            sum ^= *iter;
        }

        int mask = 1;
        for (mask = 1;; mask = mask << 1) {
            if ((sum & mask) != 0) {
                // 这一位，两个不相等的数不同
                break;
            }
        }

        ret[0] = ret[1] = 0;
        for (vector<int>::iterator iter = nums.begin(); iter != nums.end();
             ++iter) {
            if ((*iter & mask) == 0) {
                ret[0] ^= *iter;
            } else {
                ret[1] ^= *iter;
            }
        }

        return ret;
    }
};

int main(void) {
    Solution solution;

    vector<int> list = {4, 1, 4, 6};
    vector<int> ret;
    ret = solution.singleNumbers(list);

    for (vector<int>::iterator iter = ret.begin(); iter != ret.end(); ++iter) {
        cout << *iter << " ";
    }
    cout << endl;

    return 0;
}