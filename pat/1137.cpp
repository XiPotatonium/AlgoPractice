#include <algorithm>
#include <cmath>
#include <iostream>
#include <memory>
#include <unordered_map>
#include <vector>

using namespace std;

struct Student {
    string id;
    int gonline;
    int gmid;
    int gfinal;
    int g;

    Student(const string &id) : id(id) { gonline = gmid = gfinal = g = -1; }

    void grade() { g = roundl(gmid > gfinal ? (0.4 * gmid + 0.6 * gfinal) : gfinal); }
};

bool pred(const shared_ptr<Student> &a, const shared_ptr<Student> &b) {
    if (a->g == b->g) {
        return a->id < b->id;
    } else {
        return a->g > b->g;
    }
}

int main(void) {
    int p, m, n;
    string s;

    cin >> p >> m >> n;

    unordered_map<string, shared_ptr<Student>> id_stu_map;

    for (int i = 0; i < p; ++i) {
        cin >> s;
        if (id_stu_map.find(s) == id_stu_map.end()) {
            id_stu_map.emplace(s, new Student(s));
        }
        cin >> id_stu_map[s]->gonline;
    }
    for (int i = 0; i < m; ++i) {
        cin >> s;
        if (id_stu_map.find(s) == id_stu_map.end()) {
            id_stu_map.emplace(s, new Student(s));
        }
        cin >> id_stu_map[s]->gmid;
    }
    for (int i = 0; i < n; ++i) {
        cin >> s;
        if (id_stu_map.find(s) == id_stu_map.end()) {
            id_stu_map.emplace(s, new Student(s));
        }
        cin >> id_stu_map[s]->gfinal;
    }

    vector<shared_ptr<Student>> stus;

    for (auto &stu_kv : id_stu_map) {
        stu_kv.second->grade();
        // mgj 题目里的final grade不是gfinal，是g
        if (stu_kv.second->gonline >= 200 && stu_kv.second->g >= 60) {
            stus.emplace_back(stu_kv.second);
        }
    }

    sort(stus.begin(), stus.end(), pred);

    for (auto &stu : stus) {
        printf("%s %d %d %d %d\n", stu->id.c_str(), stu->gonline, stu->gmid, stu->gfinal, stu->g);
    }

    return 0;
}