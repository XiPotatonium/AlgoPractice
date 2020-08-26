/// 偶数个元音的子串
/// 官方题解用了pred，但我感觉偶数天然用异或很好
/// 官方题解pred和哈希表的思想很像560

#include <iostream>
#include <queue>
#include <unordered_map>
#include <vector>

using namespace std;

#define ISVOWEL(c)                                                             \
    ((c) == 'a' || (c) == 'e' || (c) == 'i' || (c) == 'o' || (c) == 'u')

class Solution {
public:
    int findTheLongestSubstring(string s) {
        int ret = 0;
        unordered_map<char, int> map;
        map.insert(make_pair(0, -1));

        char sum = 0;
        for (int i = 0; i < s.size(); ++i) {
            if (ISVOWEL(s[i])) {
                sum ^= s[i];
            }
            auto v = map.find(sum);
            if (v != map.end()) {
                if (i - v->second > ret) {
                    ret = i - v->second;
                }
            } else {
                map.insert(make_pair(sum, i));
            }
        }

        return ret;
    }
};

int main(void) {

    Solution s;
    vector<vector<int>> v = {{1, 0}};

    cout << s.findTheLongestSubstring("leetcodeisgreat") << endl;

    return 0;
}