/// 看完题目再动键盘，切记

#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

// id -> idx
unordered_map<int, int> male;
unordered_map<int, int> female;

// adi[i][j] = abs(id(j))
vector<vector<int>> adj;

bool pred(vector<int> &a, vector<int> &b) {
    if (a[0] < b[0]) {
        return true;
    } else if (a[0] == b[0]) {
        return a[1] < b[1];
    } else {
        return false;
    }
}

int try_get_idx(int id, bool is_male) {
    static int s_cur = 0;

    unordered_map<int, int>::iterator iter;

    if (is_male) {
        iter = male.find(id);
        if (iter == male.end()) {
            male[id] = s_cur++;
        } else {
            return iter->second;
        }
    } else {
        iter = female.find(id);
        if (iter == female.end()) {
            female[id] = s_cur++;
        } else {
            return iter->second;
        }
    }
    return s_cur - 1;
}

vector<vector<int>> foo(int a, bool a_male, int b, bool b_male) {
    vector<vector<int>> ret;
    int a_idx, b_idx;
    unordered_map<int, int>::iterator iter;

    if (a_male) {
        iter = male.find(a);
        if (iter == male.end()) {
            return ret;
        }
    } else {
        iter = female.find(a);
        if (iter == female.end()) {
            return ret;
        }
    }
    a_idx = iter->second;

    if (b_male) {
        iter = male.find(b);
        if (iter == male.end()) {
            return ret;
        }
    } else {
        iter = female.find(b);
        if (iter == female.end()) {
            return ret;
        }
    }
    b_idx = iter->second;

    vector<int> cs;
    for (int i = 0; i < adj.size(); ++i) {
        int c = adj[a_idx][i];

        if (c >= 0 && c != b &&
            ((a_male && male.find(c) != male.end()) ||
             (!a_male && female.find(c) != female.end()))) {
            cs.push_back(c);
        }
    }

    int d;
    for (int i = 0; i < adj.size(); ++i) {
        d = adj[b_idx][i];
        if (d == a) {
            continue;
        }

        if (b_male) {
            iter = male.find(d);
            if (iter == male.end()) {
                continue;
            }
        } else {
            iter = female.find(d);
            if (iter == female.end()) {
                continue;
            }
        }

        for (int i = 0; i < cs.size(); ++i) {
            int c_idx =
                a_male ? male.find(cs[i])->second : female.find(cs[i])->second;
            if (adj[iter->second][c_idx] >= 0) {
                ret.push_back({cs[i], d});
            }
        }
    }

    sort(ret.begin(), ret.end(), pred);
    return ret;
}

void get_in(int &id, bool &is_male) {
    static string s;
    cin >> s;
    id = atoi(s.c_str());
    is_male = s[0] != '-';
    id = id < 0 ? -id : id;
}

int main(void) {
    int n, m, a, b;
    bool is_male_a, is_male_b;
    string sa, sb;
    cin >> n >> m;

    adj = vector<vector<int>>(n, vector<int>(n, -1));

    for (int i = 0; i < m; ++i) {
        get_in(a, is_male_a);
        get_in(b, is_male_b);
        int a_idx = try_get_idx(a, is_male_a);
        int b_idx = try_get_idx(b, is_male_b);
        adj[a_idx][b_idx] = b;
        adj[b_idx][a_idx] = a;
    }

    cin >> m;

    for (int i = 0; i < m; ++i) {
        get_in(a, is_male_a);
        get_in(b, is_male_b);
        vector<vector<int>> res = foo(a, is_male_a, b, is_male_b);
        cout << res.size() << endl;
        for (int i = 0; i < res.size(); ++i) {
            printf("%04d %04d\n", res[i][0], res[i][1]);
        }
    }

    return 0;
}