#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int> &nums) {
        vector<vector<int>> ret;
        sort(nums.begin(), nums.end());
        for (int a = 0; a < nums.size(); ++a) {
            if (a > 0 && nums[a - 1] == nums[a]) {
                continue; // 去重
            }

            int remainder = -nums[a];
            int c = nums.size() - 1;
            for (int b = a + 1; b < c; ++b) {
                if (b > a + 1 && nums[b - 1] == nums[b]) {
                    continue; // 去重
                }

                // 定位c
                while (b < c && nums[b] + nums[c] > remainder) {
                    --c;
                }

                if (b == c) {
                    // 提前退出
                    break;
                }

                if (nums[b] + nums[c] == remainder) {
                    ret.push_back({nums[a], nums[b], nums[c]});
                }
            }
        }

        return ret;
    }
};

int main(void) {

    vector<int> nums = {-1, 0, 1, 2, -1, -4};

    Solution s;
    auto ans = s.threeSum(nums);
    for (auto &v : ans) {
        for (auto i : v) {
            cout << i << ' ';
        }
        cout << endl;
    }

    return 0;
}