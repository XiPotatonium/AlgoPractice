#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

/// <summary>
/// 并查集
/// </summary>
class Solution {
    vector<int> &father;
    vector<int> &is_root;

public:
    Solution(vector<int>& father, vector<int>&is_root)
        : father(father), is_root(is_root){

    }

    void solve() {

    }
};


int main(void) {
    int n;
    cin >> n;

	return 0; 
}

/// <summary>
/// 二部图遍历算法，比较直观但是不是很好
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
                        // 还未被删除
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
