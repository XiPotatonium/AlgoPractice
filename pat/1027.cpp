#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

int main() {
    int earth[3];
    char mars[7];

    cin >> earth[0] >> earth[1] >> earth[2];

    for (int i = 0; i < 3; ++i) {
        mars[2 * i] = earth[i] / 13;
        mars[2 * i + 1] = earth[i] % 13;
    }
    for (int i = 0; i < 6; ++i) {
        if (mars[i] < 10) {
            mars[i] += '0';
        } else {
            mars[i] += 'A' - 10;
        }
    }
    mars[6] = 0;

    printf("#%s", mars);

    return 0;
}
