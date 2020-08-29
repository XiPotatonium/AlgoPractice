#include <iostream>
#include <string>

using namespace std;

// -?[0-9]+(.[0-9]+)?
bool try_parse_double(const string &str, double &num) {
#define ISNUM(a) ((a) >= '0' && (a) <= '9')

    if (str.length() == 0) {
        return false;
    }
    int i = 0;
    if (str[0] == '-') {
        ++i;
    }

    for (; i < str.length() && ISNUM(str[i]); ++i)
        ;

    if (i < str.length()) {
        if (str[i] == '.') {
            int dot_idx = i;
            ++i;
            for (; i < str.length() && ISNUM(str[i]); ++i)
                ;

            if (i < str.length()) {
                // 小数部分的非法字符
                return false;
            } else if (i - 1 - dot_idx > 2) {
                // 最多两位有效数字
                return false;
            }
        } else {
            // 整数部分的非法字符
            return false;
        }
    }

#undef ISNUM
    num = atof(str.c_str());
    return true;
}

int main(void) {
    int n;
    cin >> n;

    string s;
    double num;
    double sum = 0;
    int cnt = 0;
    for (int i = 0; i < n; ++i) {
        cin >> s;

        if (!try_parse_double(s, num)) {
            printf("ERROR: %s is not a legal number\n", s.c_str());
        } else if (num < -1000 || num > 1000) {
            printf("ERROR: %s is not a legal number\n", s.c_str());
        } else {
            sum += num;
            ++cnt;
        }
    }

    if (cnt == 0) {
        printf("The average of 0 numbers is Undefined\n");
    } else if (cnt == 1) {
        printf("The average of 1 number is %.2lf\n", cnt, sum);
    } else {
        printf("The average of %d numbers is %.2lf\n", cnt, sum / cnt);
    }
    return 0;
}