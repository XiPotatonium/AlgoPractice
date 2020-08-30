#include <array>
#include <iostream>
#include <set>
#include <vector>

using namespace std;

enum class KeyState {
    NotAppear, // 未出现
    Possible,  // 可能stuck
    Impossible // 没有stuck
};

int main(void) {
    int k;
    string str;
    cin >> k >> str;

    array<KeyState, 128> key_stat;
    for (auto &i : key_stat) {
        i = KeyState::NotAppear;
    }

    int cnt = 1;
    for (int i = 1; i < str.size(); ++i) {
        if (str[i] == str[i - 1]) {
            ++cnt;
        } else {
            //
            if (cnt % k != 0) {
                key_stat[str[i - 1]] = KeyState::Impossible;
            } else if (key_stat[str[i - 1]] == KeyState::NotAppear) {
                key_stat[str[i - 1]] = KeyState::Possible;
            }
            cnt = 1;
        }
    }
    // 最后一组
    if (cnt % k != 0) {
        key_stat[str[str.size() - 1]] = KeyState::Impossible;
    } else if (key_stat[str[str.size() - 1]] == KeyState::NotAppear) {
        key_stat[str[str.size() - 1]] = KeyState::Possible;
    }

    string res;
    res.reserve(str.size());
    set<char> printed;

    for (int i = 0; i < str.size(); ++i) {
        if (key_stat[str[i]] == KeyState::Possible) {
            i += k - 1; // 跳过多余的
            if (printed.find(str[i]) == printed.end()) {
                // 未被打印
                putchar(str[i]);
                printed.insert(str[i]);
            }
        }
        res += str[i];
    }
    printf("\n%s", res.c_str());

    return 0;
}