// ����ǰ׺������ԭ�ַ����м��� �ǿ� ǰ׺Ҳ�Ǻ�׺��������ԭ�ַ����������ַ�����
// ����һ���ַ��� s�����㷵������ �����ǰ׺��
// ������������������ǰ׺���򷵻�һ�����ַ�����

// ͷһ�μ�����Ҫ��ȷ������
// ��������ȥ�ж�eq�ᳬʱ�ģ�ֱ���ù�ϣ�������eq�жϣ���������ײ

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    string longestPrefix(string s) {
        if (s.length() == 1) {
            return "";
        }

        int s_len = s.length();
        int len = 1;
        int prefix_hash = s[0] - 'a';
        int postfix_hash = s[s_len - 1] - 'a';
        int max_len = s[0] == s[s_len - 1] ? 1 : 0;

        int postfix_base = 26;

        for (len = 2; len < s_len; ++len) {
            prefix_hash = ((prefix_hash * 26) % 82595483 + (s[len - 1] - 'a')) % 82595483;
            postfix_hash = (postfix_hash + ((s[s_len - len] - 'a') * postfix_base) % 82595483) % 82595483;
            postfix_base = (postfix_base * 26) % 82595483;

            if (prefix_hash == postfix_hash) {
                // bool eq = true;
                // for (int i = 0; i < len; ++i) {
                //    if (s[i] != s[s_len - len + i]) {
                //        eq = false;
                //        break;
                //    }
                //}
                // if (eq) {
                //    max_len = len;
                //}
                max_len = len;
            }
        }

        if (max_len == 0) {
            return "";
        } else {
            return s.substr(0, max_len);
        }
    }
};

// 2147483629
// 82595483
// 16777213

int foo() {
    int n = INT32_MAX / 26;

    for (; n > 0; --n) {
        bool prime = true;
        for (int i = 2; i * i <= n; ++i) {
            if (n % i == 0) {
                prime = false;
                break;
            }
        }
        if (prime) {
            return n;
        }
    }

    return -1;
}

int main(void) {

    Solution s;
    cout << s.longestPrefix("ababab") << endl;

    // cout << foo() << endl;

    return 0;
}
