#include <algorithm>
#include <array>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

/// <summary>
/// ���鼯
/// </summary>
class Solution {
    vector<int> parent;

    int find_root(int x) {
        int tail = x;
        while (parent[x] != x) {
            x = parent[x];
        }
        int root = x;
        // ·��ѹ��
        x = tail;
        while (root != x) {
            int f = parent[x];
            parent[x] = root;
            x = f;
        }
        return root;
    }

    /// <summary>
    /// a��ӵ�b�ļ�����
    /// </summary>
    /// <param name="a"></param>
    /// <param name="b"></param>
    void do_union(int a, int b) {
        int root_a = find_root(a);
        int root_b = find_root(b);
        if (root_a != root_b) {
            parent[root_a] = root_b;
        }
    }

public:
    Solution(int n) : parent(n) {
        for (int i = 0; i < n; ++i) {
            parent[i] = i;
        }
    }

    void solve() {
        array<int, 1000> hobbies;
        for (int &i : hobbies) {
            i = -1;
        }

        int ni, x;

        for (int i = 0; i < parent.size(); ++i) {
            scanf("%d: ", &ni);
            for (int j = 0; j < ni; ++j) {
                scanf("%d", &x);
                --x; // [1, 1000] -> [0, 1000)
                if (hobbies[x] < 0) {
                    // ���ǵ�һ��ϲ�����hobby����
                    hobbies[x] = i;
                }
                // ���������ӵ���һ��ϲ��x���˵�group��
                // QUESTION �����find_root����û�б�Ҫ
                do_union(i, find_root(hobbies[x]));
            }
        }

        // ÿ��root���м�����
        vector<int> res(parent.size());
        for (int i = 0; i < parent.size(); ++i) {
            ++res[find_root(i)];
        }
        sort(res.begin(), res.end(), greater<int>());

        int grp_cnt = 0;
        for (; res[grp_cnt] != 0; ++grp_cnt)
            ;
        printf("%d\n", grp_cnt);

        for (int i = 0; i < grp_cnt; ++i) {
            if (i != 0) {
                printf(" ");
            }
            printf("%d", res[i]);
        }
    }
};

int main(void) {
    int n;
    cin >> n;

    Solution s(n);
    s.solve();

    return 0;
}

/// <summary>
/// ����ͼ�����㷨���Ƚ�ֱ�۵��ǲ��Ǻܺ�
/// </summary>
void graph_traverse() {
    vector<vector<int>> hobbies(1000);
    vector<vector<int>> person;

    int n;
    cin >> n;

    for (int i = 0; i < n; ++i) {
        int ni;
        scanf("%d: ", &ni);
        person.push_back(vector<int>(ni));
        for (int j = 0; j < ni; ++j) {
            cin >> person[i][j];
            --person[i][j]; // [1, 1000] -> [0, 1000)
            hobbies[person[i][j]].push_back(i);
        }
    }

    vector<int> grps;
    while (1) {
        int start_person_idx = -1;
        for (int i = 0; i < person.size(); ++i) {
            if (person[i].size() != 0) {
                start_person_idx = i;
                break;
            }
        }

        if (start_person_idx < 0) {
            break;
        }

        int cnt = 0;
        queue<int> hobby_q;
        queue<int> person_q;
        person_q.push(start_person_idx);

        while (1) {
            if (person_q.empty()) {
                break;
            }

            while (!person_q.empty()) {
                int p_idx = person_q.front();
                person_q.pop();

                for (int h_idx : person[p_idx]) {
                    hobby_q.push(h_idx);
                }

                ++cnt;
                person[p_idx] = {};
            }

            if (hobby_q.empty()) {
                break;
            }

            while (!hobby_q.empty()) {
                int h_idx = hobby_q.front();
                hobby_q.pop();

                for (int p_idx : hobbies[h_idx]) {
                    if (person[p_idx].size() != 0) {
                        // ��δ��ɾ��
                        person_q.push(p_idx);
                    }
                }
            }
        }

        grps.push_back(cnt);
    }

    sort(grps.begin(), grps.end(), greater<int>());

    cout << grps.size() << endl;
    for (int i = 0; i < grps.size(); ++i) {
        if (i != 0) {
            cout << " ";
        }
        cout << grps[i];
    }
}
