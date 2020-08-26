/// ����ظ��Ӵ���ע����ĸ�������޵ģ������ñ�
/// ������һ�ַ��������ٵ�ǰλ��֮ǰ�����һ�����ظ��Ӵ�����һ�����ڱ��ʾ������ظ��Ӵ�������Щֵ
/// ����һ�������Ǽ�¼������ĸ��һ�γ�����ʲôλ�ã���ȻҲ��Ҫ�������һ�����ظ��Ӵ�

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