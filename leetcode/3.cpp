/// 最长不重复子串，注意字母表是有限的，可以用表
/// 这里是一种方法，跟踪当前位置之前的最后一个不重复子串，用一个存在表表示这个不重复子串中有哪些值
/// 还有一个方案是记录所有字母上一次出现在什么位置，当然也需要跟踪最后一个不重复子串

#include <iostream>
#include <queue>
#include <vector>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int head = 0, tail = 0;
        int ret = 0;
        bool exists[128] = {false};
        while (tail < s.size()) {
            if (!exists[s[tail]]) {
                exists[s[tail]] = true;
                ++tail;
                ret = (tail - head) > ret ? tail - head : ret;
            } else {
                exists[s[head]] = false;
                ++head;
            }
        }
        return ret;
    }
};

int main(void) {
    Solution solution;

    cout << solution.lengthOfLongestSubstring("pwwkew");

    return 0;
}