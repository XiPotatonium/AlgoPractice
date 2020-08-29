// 这道题的正确解法应该是KMP

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
    // 仔细挑选，质数不容易出错
    static constexpr int modulus = 1000000007;

public:
    string shortestPalindrome(string s) {
        if (s.length() == 0) {
            return "";
        }
        long long hash1 = 0, hash2 = 0;

        long long base = 1;
        vector<int> candidates;
        for (int i = 0; i < s.size(); ++i) {
            hash1 = (hash1 * 128 + s[i]) % modulus;
            hash2 = (hash2 + s[i] * base) % modulus;
            base = (base * 128) % modulus;

            if (hash1 == hash2) {
                candidates.push_back(i + 1);
            }
        }

        // 检查
        int res;
        for (auto iter = candidates.crbegin(); iter != candidates.crend(); ++iter) {
            res = *iter;
            int i = 0;
            for (; i < res; ++i) {
                if (s[i] != s[res - i - 1]) {
                    break;
                }
            }
            if (i == res) {
                break;
            }
        }

        string ret;
        ret.reserve(2 * s.length() - candidates[candidates.size() - 1]);
        for (int i = s.length() - 1; i >= candidates[candidates.size() - 1]; --i) {
            ret += s[i];
        }
        ret += s;

        return ret;
    }
};

int main(void) {

    Solution s;
    cout << s.shortestPalindrome(
                "abcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwx"
                "yzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuv"
                "wxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrst"
                "uvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqr"
                "stuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnop"
                "qrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmn"
                "opqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijkl"
                "mnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghij"
                "klmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyz")
         << endl;

    return 0;
}s