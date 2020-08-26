/// atoi
/// 没啥好说的

#include <iostream>
#include <queue>
#include <vector>

using namespace std;

#define ISSPACE(c) ((c) == ' ' || (c) == '\t' || (c) == '\r' || (c) == '\n')
#define ISDIGIT(c) ((c) >= '0' && (c) <= '9')

class Solution {
public:
    int myAtoi(string str) {
        int i = 0;
        while (i < str.size() && ISSPACE(str[i])) {
            ++i;
        }
        bool neg = false;
        if (str[i] == '-') {
            neg = true;
            ++i;
        } else if (str[i] == '+') {
            ++i;
        }

        long long res = 0;
        for (; i < str.size(); ++i) {
            if (!ISDIGIT(str[i])) {
                break;
            }
            res *= 10;
            res += str[i] - '0';
            if (res > INT32_MAX && !neg) {
                return INT32_MAX;
            } else if (-res < INT32_MIN && neg) {
                return INT32_MIN;
            }
        }

        return neg ? -res : res;
    }
};

int main(void) {
    Solution solution;

    cout << solution.myAtoi("42") << endl;
    cout << solution.myAtoi("   -42") << endl;
    cout << solution.myAtoi("4193 with words") << endl;
    cout << solution.myAtoi("words and 987") << endl;
    cout << solution.myAtoi("-91283472332") << endl;

    return 0;
}