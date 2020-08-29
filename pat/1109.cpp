/// Formation is very important when taking a group photo. Given the rules of forming K rows with N people as the
/// following:
///
/// 1. The number of people in each row must be N / K (round down to the nearest integer), with all the extra
///     people(if any) standing in the last row;
/// 2. All the people in the rear row must be no shorter than anyone standing in the front rows;
/// 3. In each row, the tallest one stands at the central position (which is defined to be the position (m / 2 + 1),
///     where m is the total number of people in that row, and the division result must be rounded down to the nearest
///     integer);
/// 4. In each row, other people must enter the row in non-increasing order of their heights,
///     alternately taking their positions first to the right and then to the left of the tallest
///     one (For example, given five people with their heights 190, 188, 186, 175, and170,
///     the final formation would be 175, 188, 190, 186, and 170.
///     Here we assume that you are facing the group so your left-hand side is the right-hand side of the one at the
///     central position.);
/// 5. When there are many people having the same height, they must be ordered in alphabetical(increasing) order of
/// their names,
///		and it is guaranteed that there is no duplication of names.

#include <algorithm>
#include <iostream>
#include <memory>
#include <vector>

using namespace std;

struct Person {
    int height;
    string name;

    Person(int height, string &&name) : height(height), name(name) {}
};

bool pred(const shared_ptr<Person> &a, const shared_ptr<Person> &b) {
    if (a->height == b->height) {
        return a->name > b->name;
    } else {
        return a->height < b->height;
    }
}

int main(void) {
    int n, k;
    cin >> n >> k;

    vector<shared_ptr<Person>> persons(n);
    string name;
    int height;
    for (int i = 0; i < n; ++i) {
        cin >> name >> height;
        persons[i] = shared_ptr<Person>(new Person(height, std::move(name)));
    }

    sort(persons.begin(), persons.end(), pred);

    vector<vector<shared_ptr<Person>>> formation;

    int division = n / k;
    int person_idx = -1 - division;
    for (int row = 0; row < k; ++row) {
        int m = division; // 一行最多人数
        if (row == k - 1) {
            m = n - (k - 1) * division;
        }
        person_idx += m + division;

        formation.push_back(vector<shared_ptr<Person>>(m));
        auto &thisrow = formation[formation.size() - 1];

        // 填最高的人
        int left = m / 2 - 1, right = m / 2 + 1;
        thisrow[m / 2] = persons[person_idx--];
        while (left >= 0 || right < thisrow.size()) {
            if (left >= 0) {
                thisrow[left--] = persons[person_idx--];
            }
            if (right < thisrow.size()) {
                thisrow[right++] = persons[person_idx--];
            }
        }
    }

    for (auto iter = formation.crbegin(); iter != formation.crend(); ++iter) {
        for (auto jter = iter->cbegin(); jter != iter->cend(); ++jter) {
            if (jter != iter->cbegin()) {
                printf(" ");
            }
            printf("%s", (*jter)->name.c_str());
        }
        printf("\n");
    }

    return 0;
}