/// 给你一个字符串 S、一个字符串 T，请在字符串 S 里面找出：包含 T 所有字符的最小子串。
/// 滑动窗口，貌似也很常见的思路

#include <unordered_map>

class Solution {
public:
    string minWindow(string s, string t) {
        int minl = -1, minr = -1;

        unordered_map<char, int> chmap;
        for (int i = 0; i < t.size(); ++i) {
            unordered_map<char, int>::iterator iter = chmap.find(t[i]);
            if (iter != chmap.end()) {
                iter->second++;
            } else {
                chmap.insert(make_pair(t[i], 1));
            }
        }

        for (int l = 0, r = 0; r <= s.size();) {
            unordered_map<char, int>::iterator iter;
            for (; r < s.size(); ++r) {
                iter = chmap.find(s[r]);
                if (iter != chmap.end()) {
                    iter->second--;
                }
                for (iter = chmap.begin(); iter != chmap.end(); ++iter) {
                    if (iter->second > 0) {
                        break;
                    }
                }
                if (iter == chmap.end()) {
                    ++r;
                    break; // 如果每个字符都小于等于0，也就是说全部找到了，就退出
                } else if (r == s.size() - 1) {
                    //已经是最后一个了但是仍然没有找齐
                    goto ret;
                }
            }
            for (; l < r; ++l) {
                if (minr < 0 || r - l < minr - minl) {
                    minr = r;
                    minl = l;
                }
                iter = chmap.find(s[l]);
                if (iter != chmap.end()) {
                    iter->second++;

                    for (iter = chmap.begin(); iter != chmap.end(); ++iter) {
                        if (iter->second > 0) {
                            break;
                        }
                    }
                    if (iter != chmap.end()) {
                        ++l;
                        break; // 有一个字符大于0，也就是说已经不够的时候，就退出
                    }
                }
            }
            if (r == s.size()) {
                break;
            }
        }

    ret:
        if (minl < 0) {
            return "";
        }
        return s.substr(minl, minr - minl);
    }
};