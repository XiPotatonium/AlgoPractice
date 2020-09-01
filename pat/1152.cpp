#include <iostream>
#include <vector>

using namespace std;

bool check_prime(const int num) {
    if (num == 1) {
        return false;
    }
    if (num == 2 || num == 3) {
        return true;
    }

    for (int i = 2; i * i <= num; ++i) {
        if (num % i == 0) {
            return false;
        }
    }
    return true;
}

int main(void) {
    int l, k;
    string seq;

    cin >> l >> k >> seq;

    string fmt = "%00lld\n"; // ²»ÒªÍü¼Ç²¹0
    fmt[2] += k;             // k < 10

    // K > L ?
    long long num = 0;
    long long base = 1;

    int i = 0;
    for (i = k - 2; i >= 0; --i) {
        num += base * (seq[i] - '0');
        base *= 10;
    }
    for (i = k - 1; i < l; ++i) {
        num = num % base * 10 + seq[i] - '0';
        if (check_prime(num)) {
            printf(fmt.c_str(), num);
            break;
        }
    }

    if (i == l) {
        printf("404\n");
    }

    return 0;
}