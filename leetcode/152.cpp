/// 最大积子数组

class Solution {
private:
public:
    int maxProduct(vector<int> &nums) {
        int cur = 1;
        int neg = 0;
        int ret = nums[0];

        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] < 0) {
                if (neg != 0) {
                    int tmp = neg * nums[i];
                    neg = cur * nums[i];
                    cur = tmp;
                } else {
                    neg = cur * nums[i];
                    cur = 1;
                    continue;
                }
            } else if (nums[i] == 0) {
                cur = 1;
                neg = 0;
                if (ret < 0) {
                    ret = 0;
                }
                continue;
            } else {
                cur *= nums[i];
                neg *= nums[i];
            }
            if (cur > ret) {
                ret = cur;
            }
        }

        return ret;
    }

    /// 最大和子数组
    int maxSum(vector<int> &nums) {
        int cur = 0;
        int ret = nums[0];
        for (int i = 0; i < nums.size(); ++i) {
            if (cur + nums[i] > cur) {
                cur += nums[i];
            } else {
                cur = nums[i];
            }
            if (cur > ret) {
                ret = cur;
            }
        }
        return ret;
    }
};