/// 正则表达式，因为较为简单，所以不需要做状态机
/// 但是需要

#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    bool isMatch(string s, string p)
    {
        return _isMatch(s.c_str(), p.c_str());
    }

    bool _isMatch(const char* s, const char* p)
    {
        if (*s == '\0' && *p == '\0') {
            return true;
        } else if (*p == '\0') {
            return false;
        }

        if (p[1] == '*') {
            if (*p == '.') {
                while (true) {
                    if (_isMatch(s, p + 2)) {
                        return true;
                    }
                    if (*s != '\0') {
                        s++;
                    } else {
                        break;
                    }
                }
                return false;
            } else {
                while (true) {
                    if (_isMatch(s, p + 2)) {
                        return true;
                    }
                    if (*s == *p) {
                        s++;
                    } else {
                        break;
                    }
                }
                return false;
            }
        } else if (*s != '\0') {
            if (*p == '.') {
                return _isMatch(s + 1, p + 1);
            } else {
                return *p == *s && _isMatch(s + 1, p + 1);
            }
        }
        return false;
    }
};

int main(void)
{
    Solution solution;

    cout << solution.isMatch("a", "ab*");

    return 0;
}