// 并查集，寻找家族

#include <algorithm>
#include <iostream>
#include <memory>
#include <set>
#include <vector>

using namespace std;

vector<int> s_parent;
vector<int> s_estate;
vector<int> s_area;

int find_root(int x) {
    int tail = x;
    while (x != s_parent[x]) {
        x = s_parent[x];
    }
    int root = x;
    x = tail;
    while (x != root) {
        int f = s_parent[x];
        s_parent[x] = root;
        x = f;
    }

    // 忘记return，使用clang，在这个问题中居然会报illegal inst的错误，人傻了
    return root;
}

void do_union(int a, int b) {
    int root_a = find_root(a);
    int root_b = find_root(b);
    if (root_a != root_b) {
        s_parent[root_a] = root_b;
    }
}

set<int> valid_idx;

struct Family {
    unique_ptr<vector<int>> members;
    int min_id;
    double avg_area;
    double avg_estate;

    Family(unique_ptr<vector<int>> &family_members, int total_estate, int total_area)
        : members(std::move(family_members)) {
        min_id = INT32_MAX;
        for (int &id : *members) {
            if (id < min_id) {
                min_id = id;
            }
        }

        avg_estate = (double)total_estate / members->size();
        avg_area = (double)total_area / members->size();
    }

    bool operator<(const Family &b) const {
        if (avg_area == b.avg_area) {
            return min_id < b.min_id;
        } else {
            return avg_area > b.avg_area;
        }
    }
};

int main(void) {
    s_parent = vector<int>(10000);
    s_estate = vector<int>(10000);
    s_area = vector<int>(10000);

    for (int i = 0; i < s_parent.size(); ++i) {
        s_parent[i] = i;
        s_estate[i] = 0;
        s_area[i] = 0;
    }

    int n, id, father, mother, k, child;

    cin >> n;

    for (int i = 0; i < n; ++i) {
        cin >> id >> father >> mother >> k;

        valid_idx.insert(id);
        if (father >= 0) {
            valid_idx.insert(father);
            do_union(id, father);
        }
        if (mother >= 0) {
            valid_idx.insert(mother);
            do_union(id, mother);
        }

        for (int j = 0; j < k; ++j) {
            cin >> child;
            valid_idx.insert(child);
            do_union(id, child);
        }
        cin >> s_estate[id] >> s_area[id];
    }

    // 每个root对应的家族有哪些人
    vector<unique_ptr<vector<int>>> vs(10000);

    for (int idx : valid_idx) {
        int root = find_root(idx);
        if (vs[root] == nullptr) {
            vs[root] = unique_ptr<vector<int>>(new vector<int>());
        }
        vs[root]->push_back(idx);
    }

    // 建家族
    vector<Family> families;

    for (unique_ptr<vector<int>> &v : vs) {
        if (v == nullptr) {
            continue;
        }
        int total_estate = 0;
        int total_ares = 0;
        for (int idx : *v) {
            total_ares += s_area[idx];
            total_estate += s_estate[idx];
        }
        families.emplace_back(v, total_estate, total_ares);
    }

    sort(families.begin(), families.end());

    cout << families.size() << endl;

    for (Family &f : families) {
        printf("%04d %d %.3f %.3f\n", f.min_id, f.members->size(), f.avg_estate, f.avg_area);
    }

    return 0;
}