/// 求平方根，牛顿迭代法

#include <iostream>
#include <queue>
#include <vector>

using namespace std;

class Solution {
public:
    int mySqrt(int x) {
        long long guess = 1;
        while (true) {
            long long tmp = guess * guess;
            if (tmp == x || (tmp < x && (guess + 1) * (guess + 1) > x)) {
                return guess;
            } else {
                guess = (x / guess + guess) / 2;
            }
        }
    }
};

int main(void) {
    Solution solution;

    cout << solution.mySqrt(23) << endl;
    cout << solution.mySqrt(2) << endl;
    cout << solution.mySqrt(4) << endl;
    cout << solution.mySqrt(8) << endl;
    cout << solution.mySqrt(16) << endl;
    cout << solution.mySqrt(0) << endl;
    cout << solution.mySqrt(5) << endl;

    return 0;
}