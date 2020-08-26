// �������״����
// ����֦����ΪҪ��������͵��Ǹ�
// ����Ҫ��С��base��ʼö�٣���Ϊ�����tieҪ���ֵ��򣨴�С�Ŀ�ʼö�٣����ʱ���������

#include <iostream>
#include <vector>

using namespace std;

int res_sum = INT32_MIN;
vector<int> res;
vector<int> tmp;
int N, K, P;

void find(int remainder) {
    if (remainder == 0 && tmp.size() == K) {
        int sum = 0;
        for (int i : tmp) {
            sum += i;
        }
        if (sum >= res_sum) {
            res = tmp;
            res_sum = sum;
        }
        return;
    } else if (remainder == 0 || tmp.size() == K) {
        return;
    }

    int base = 1;
    if (tmp.size() != 0) {
        base = tmp[tmp.size() - 1];
    }

    for (;; ++base) {
        int term = base;
        for (int i = 0; i < P - 1; ++i) {
            term *= base;
        }

        if (remainder >= term) {
            tmp.push_back(base);
            find(remainder - term);
            tmp.erase(tmp.end() - 1);
        } else {
            break;
        }
    }
}

int main(void) {
    cin >> N >> K >> P;

    find(N);
    if (res_sum > 0) {
        cout << N;
        for (auto iter = res.crbegin(); iter != res.crend(); ++iter) {
            if (iter != res.crbegin()) {
                cout << " + " << *iter << "^" << P;
            } else {
                cout << " = " << *iter << "^" << P;
            }
        }
    } else {
        cout << "Impossible\n";
    }

    return 0;
}