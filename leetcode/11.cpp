#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxArea(vector<int> &height) {
        int l = 0, r = height.size() - 1;
        int max_area = INT32_MIN;

        while (l != r) {
            max_area = max(max_area, min(height[l], height[r]) * (r - l));
            if (height[l] < height[r]) {
                ++l;
            } else {
                --r;
            }
        }

        return max_area;
    }
};

int main(void) {
    vector<int> arr = {1, 8, 6, 2, 5, 4, 8, 3, 7};

    Solution s;
    cout << s.maxArea(arr);

    return 0;
}