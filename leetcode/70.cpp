#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int climbStairs(int n) {
        if (n == 1) {
            return 1;
        }

        vector<int> fib(n);
        fib[0] = 1;
        fib[1] = 2;
        for (int i = 2; i < fib.size(); ++i) {
            fib[i] = fib[i - 1] + fib[i - 2];
        }

        return fib.back();
    }
};

int main(void) { return 0; }