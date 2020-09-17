#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int numTrees(int n) {
        vector<int> types(n);
        types[0] = 1;

        for (int i = 1; i < types.size(); ++i) {
            for (int j = 0; j <= i; ++j) {
                types[i] += (j == 0 ? 1 : types[j - 1]) * (j == i ? 1 : types[i - j - 1]);
            }
        }

        return types.back();
    }
};

int main(void) {

    Solution s;
    cout << s.numTrees(3);

    return 0;
}