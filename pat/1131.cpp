/// 这代码也太优美了，就是写代码的人脑子不太好
/// 
/// 也不是不能用BFS，只是BFS记录路径很麻烦，而这道题好巧不巧需要用路径算换成（注意不能贪心，局部最优不是全局最优）
/// 但是我没有想到DFS居然也这么快，可能是现实中线路确实不会很多，题目也说了分叉不会很多。
/// 
/// 切记4位输出要补足0，mgj demo测试数据里面居然全是4位的

#include <array>
#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

constexpr int c_limit = 10000;

array<unordered_map<int, int>, limit> s_adj;
int s_src, s_dest;
int s_best_transfer;
vector<int> s_best_path;

int cnt_transfer(vector<int> &path) {
    int cnt = 0, last_line = s_adj[path[0]][path[1]];

    for (int i = 0; i < path.size() - 1; ++i) {
        int cur_line = s_adj[path[i]][path[i + 1]];
        if (cur_line != last_line) {
            ++cnt;
            last_line = cur_line;
        }
    }

    return cnt;
}

void dfs(vector<int> &path) {
    int id = *(path.rbegin());

    if (id == s_dest) {
        int trans_cnt = cnt_transfer(path);
        if (s_best_path.size() == 0 || path.size() < s_best_path.size()) {
            s_best_path = path;
            s_best_transfer = trans_cnt;
        } else if (path.size() == s_best_path.size()) {
            if (trans_cnt < s_best_transfer) {
                s_best_path = path;
                s_best_transfer = trans_cnt;
            }
        }
    }

    for (auto &next_kv : s_adj[id]) {
        bool loop = false;
        for (int i = 0; i < path.size(); ++i) {
            if (path[i] == next_kv.first) {
                loop = true;
                break;
            }
        }
        if (loop) {
            continue;
        }

        path.push_back(next_kv.first);
        dfs(path);
        path.pop_back();
    }
}

int main(void) {
    int n, ni;
    cin >> n;

    for (int i = 0; i < n; ++i) {
        cin >> ni;

        int last_station = -1, cur_station = -1;
        for (int j = 0; j < ni; ++j) {
            last_station = cur_station;
            cin >> cur_station;
            if (last_station >= 0) {
                s_adj[last_station][cur_station] = s_adj[cur_station][last_station] = i + 1;
            }
        }
    }

    cin >> n;

    for (int i = 0; i < n; ++i) {
        cin >> s_src >> s_dest;

        vector<int> tmp_path = {s_src};
        s_best_path = vector<int>();
        s_best_transfer = INT32_MAX;
        dfs(tmp_path);

        int last_line = s_adj[s_best_path[0]][s_best_path[1]];
        int last_transfer = s_src;
        printf("%d\n", s_best_path.size() - 1);
        for (int cur = 0; cur < s_best_path.size() - 1; ++cur) {
            if (last_line != s_adj[s_best_path[cur]][s_best_path[cur + 1]]) {
                printf("Take Line#%d from %04d to %04d.\n", last_line, last_transfer, s_best_path[cur]);
                last_line = s_adj[s_best_path[cur]][s_best_path[cur + 1]];
                last_transfer = s_best_path[cur];
            }
        }
        printf("Take Line#%d from %04d to %04d.\n", last_line, last_transfer, s_dest);
    }

    return 0;
}