/// ����һ���ַ��� S��һ���ַ��� T�������ַ��� S �����ҳ������� T �����ַ�����С�Ӵ���
/// �������ڣ�ò��Ҳ�ܳ�����˼·

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
                    break; // ���ÿ���ַ���С�ڵ���0��Ҳ����˵ȫ���ҵ��ˣ����˳�
                } else if (r == s.size() - 1) {
                    //�Ѿ������һ���˵�����Ȼû������
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
                        break; // ��һ���ַ�����0��Ҳ����˵�Ѿ�������ʱ�򣬾��˳�
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