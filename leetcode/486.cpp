/// �����㷨���ܹ�
/// �Ҷ�������alpha-beta

#include <iostream>
#include <vector>

using namespace std;

class Solution {

    bool _trival(vector<int> &nums, int left, int right, int suma, int sumb, bool is_a) {
        if (left > right) {
            return suma >= sumb;
        }

        if (is_a) {
            if (_trival(nums, left + 1, right, suma + nums[left], sumb, !is_a)) {
                // �����Ӯ����֦
                return true;
            } else {
                return _trival(nums, left, right - 1, suma + nums[right], sumb, !is_a);
            }
        } else {
            if (!_trival(nums, left + 1, right, suma, sumb + nums[left], !is_a)) {
                // ���b��Ӯ����֦
                return false;
            } else {
                return _trival(nums, left, right - 1, suma, sumb + nums[right], !is_a);
            }
        }
    }

public:
    bool PredictTheWinner(vector<int> &nums) { return _trival(nums, 0, nums.size() - 1, 0, 0, true); }
};

int main(void) {

    vector<int> nums = {1, 5, 233, 7};

    Solution s;
    cout << (s.PredictTheWinner(nums) ? "true" : "false") << endl;

    return 0;
}