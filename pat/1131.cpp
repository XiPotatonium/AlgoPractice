/// �����Ҳ̫�����ˣ�����д����������Ӳ�̫��
/// 
/// Ҳ���ǲ�����BFS��ֻ��BFS��¼·�����鷳�����������ɲ�����Ҫ��·���㻻�ɣ�ע�ⲻ��̰�ģ��ֲ����Ų���ȫ�����ţ�
/// ������û���뵽DFS��ȻҲ��ô�죬��������ʵ����·ȷʵ����ܶ࣬��ĿҲ˵�˷ֲ治��ܶࡣ
/// 
/// �м�4λ���Ҫ����0��mgj demo�������������Ȼȫ��4λ��

#include <array>
#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

constexpr int limit = 10000;

array<unordered_map<int, int>, limit> s_adj;
int src, dest;

int best_transfer;
vector<int> best_path;

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

void bfs(vector<int> &path) {
    int id = *(path.rbegin());

    if (id == dest) {
        int trans_cnt = cnt_transfer(path);
        if (best_path.size() == 0 || path.size() < best_path.size()) {
            best_path = path;
            best_transfer = trans_cnt;
        } else if (path.size() == best_path.size()) {
            if (trans_cnt < best_transfer) {
                best_path = path;
                best_transfer = trans_cnt;
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
        bfs(path);
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
        cin >> src >> dest;

        vector<int> tmp_path = {src};
        best_path = vector<int>();
        best_transfer = INT32_MAX;
        bfs(tmp_path);

        int last_line = s_adj[best_path[0]][best_path[1]];
        int last_transfer = src;
        printf("%d\n", best_path.size() - 1);
        for (int cur = 0; cur < best_path.size() - 1; ++cur) {
            if (last_line != s_adj[best_path[cur]][best_path[cur + 1]]) {
                printf("Take Line#%d from %04d to %04d.\n", last_line, last_transfer, best_path[cur]);
                last_line = s_adj[best_path[cur]][best_path[cur + 1]];
                last_transfer = best_path[cur];
            }
        }
        printf("Take Line#%d from %04d to %04d.\n", last_line, last_transfer, dest);
    }

    return 0;
}