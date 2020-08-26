/// 测试点4：前导0
/// 测试点6：00.00这样的表示

#include <iostream>
#include <memory>
#include <string>
#include <vector>

using namespace std;

class FloatE {

public:
    int e;
    unique_ptr<char[]> num;
    int n;

    FloatE(string &raw, int maxn) {
        n = maxn;
        num = unique_ptr<char[]>(new char[maxn + 1]);
        num[n] = 0;
        e = 0;

        int i, j = 0;

        // 检测前导0
        for (i = 0; i < raw.size() && raw[i] == '0'; ++i)
            ;

        if (i != raw.size()) { // 不全是0
            if (raw[i] == '.') {
                ++i;
                for (; i < raw.size(); ++i) {
                    if (raw[i] != '0') {
                        break;
                    }
                    --e;
                }
                for (j = 0; j < n && i + j < raw.size(); ++j) {
                    num[j] = raw[i + j];
                }
            } else {
                int k = i;
                for (; i < raw.size(); ++i) {
                    if (raw[i] == '.') {
                        break;
                    }
                    ++e;
                }

                j = 0;

                for (; k < i && j < n; ++k) {
                    num[j++] = raw[k];
                }

                if (i < raw.size()) {
                    for (k = i + 1; k < raw.size() && j < n; ++k) {
                        num[j++] = raw[k];
                    }
                }
            }
        }

        while (j < n) {
            num[j++] = '0';
        }
        if (num[0] == '0') {
            e = 0;
        }
    }

    bool operator==(const FloatE &b) const {
        if (e != b.e) {
            return false;
        }
        for (int i = 0; i < n; ++i) {
            if (num[i] != b.num[i]) {
                return false;
            }
        }
        return true;
    }

    string to_string() {
        return string("0.") + string(num.get()) + "*10^" + std::to_string(e);
    }
};

int main() {
    int n;
    string f1, f2;
    cin >> n >> f1 >> f2;

    FloatE fe1(f1, n);
    FloatE fe2(f2, n);

    if (fe1 == fe2) {
        cout << "YES " << fe1.to_string();
    } else {
        cout << "NO " << fe1.to_string() << " " << fe2.to_string();
    }

    return 0;
}
