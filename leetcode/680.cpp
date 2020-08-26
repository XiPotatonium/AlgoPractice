/// 检查回文
/// 允许删除一个字符

#include <iostream>
#include <queue>
#include <vector>

using namespace std;

class Solution {
private:
    bool _isPalindrome(string &s, int l, int r) {
        if (l >= r) {
            return true;
        }
        if (s[l] == s[r]) {
            return _isPalindrome(s, l + 1, r - 1);
        } else {
            return false;
        }
    }
    bool _validPalindrome(string &s, int l, int r) {
        if (l >= r) {
            return true;
        }
        if (s[l] == s[r]) {
            return _validPalindrome(s, l + 1, r - 1);
        } else {
            return _isPalindrome(s, l + 1, r) || _isPalindrome(s, l, r - 1);
        }
    }

public:
    bool validPalindrome(string s) {
        return _validPalindrome(s, 0, s.size() - 1);
    }
};

int main(void) {

    Solution s;
    vector<vector<int>> v = {{1, 0}};

    auto res = s.validPalindrome("abca");

    return 0;
}