#include <iostream>
#include <unordered_map>
#include <unordered_set>

using namespace std;

bool is_prime(int num) {
    if (num == 1) {
        return false;
    } else if (num == 2 || num == 3) {
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
    int n, id;
    cin >> n;

    unordered_map<int, int> rank;

    for (int i = 1; i <= n; ++i) {
        cin >> id;
        rank[id] = i;
    }

    cin >> n;
    unordered_set<int> queried;
    for (int i = 0; i < n; ++i) {
        cin >> id;
        printf("%04d: ", id);
        if (queried.find(id) != queried.end()) {
            printf("Checked\n");
            continue;
        }

        auto r = rank.find(id);
        if (r == rank.end()) {
            printf("Are you kidding?\n");
            continue;
        }

        if (r->second == 1) {
            printf("Mystery Award\n");
        } else if (is_prime(r->second)) {
            printf("Minion\n");
        } else {
            printf("Chocolate\n");
        }
        queried.emplace(id);
    }

    return 0;
}