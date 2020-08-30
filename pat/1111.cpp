// 真TM麻烦

#include <deque>
#include <iostream>
#include <vector>

using namespace std;

struct Node {
    bool closed;
    int dist;
    int time;
    int pred;
    int count;
};

vector<vector<int>> s_adj_time;
vector<vector<int>> s_adj_len;
vector<Node> s_nodes;

int main(void) {
    int m, n;
    cin >> n >> m;

    s_adj_time = vector<vector<int>>(n, vector<int>(n));
    s_adj_len = vector<vector<int>>(n, vector<int>(n));
    s_nodes = vector<Node>(n);

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            s_adj_len[i][j] = s_adj_time[i][j] = -1;
        }
    }

    int v1, v2, one_way, length, time;
    for (int i = 0; i < m; ++i) {
        cin >> v1 >> v2 >> one_way >> length >> time;

        s_adj_time[v1][v2] = time;
        s_adj_len[v1][v2] = length;

        if (!one_way) {
            s_adj_time[v2][v1] = time;
            s_adj_len[v2][v1] = length;
        }
    }

    int src, dest;
    cin >> src >> dest;
    for (Node &node : s_nodes) {
        node.closed = false;
        node.dist = INT32_MAX;
        node.time = INT32_MAX;
        node.pred = -1;
        node.count = 0;
    }
    s_nodes[src].dist = 0;
    s_nodes[src].time = 0;

    // 寻找最短路径
    int cur = -1;
    for (;;) {
        cur = -1;
        // TODO priority_queue
        for (int i = 0; i < s_nodes.size(); ++i) {
            if (!s_nodes[i].closed && s_nodes[i].dist < INT32_MAX) {
                // 是open
                if (cur < 0 || s_nodes[i].dist < s_nodes[cur].dist) {
                    // 选最短的那个
                    cur = i;
                }
                // 这里不需要选同时最快的那个吗？
            }
        }

        if (cur < 0) {
            // 已经遍历完所有可达的节点
            break;
        }

        for (int next = 0; next < s_adj_len.size(); ++next) {
            if (s_adj_len[cur][next] < 0) {
                continue;   // 其实这里如果是closed也可以continue，不过其实没关系，不影响正确性
            }

            int new_dist = s_nodes[cur].dist + s_adj_len[cur][next];
            int new_time = s_nodes[cur].time + s_adj_time[cur][next];
            if (new_dist < s_nodes[next].dist || (new_dist == s_nodes[next].dist && new_time < s_nodes[next].time)) {
                // 更短或长度相同选最快
                // 更新路径
                s_nodes[next].dist = new_dist;
                s_nodes[next].time = new_time;
                s_nodes[next].pred = cur;
            }
        }

        s_nodes[cur].closed = true;

        if (cur == dest) {
            // 已找到终点，剪枝
            break;
        }
    }

    // 生成最短路径
    int min_len = s_nodes[dest].dist;
    deque<int> shortest;
    cur = dest;
    while (cur >= 0) {
        shortest.push_front(cur);
        cur = s_nodes[cur].pred;
    }

    // 重新初始化
    for (Node &node : s_nodes) {
        node.closed = false;
        node.dist = INT32_MAX;
        node.time = INT32_MAX;
        node.pred = -1;
        node.count = 0;
    }
    s_nodes[src].dist = 0;
    s_nodes[src].time = 0;

    // 寻找最快路径
    for (;;) {
        cur = -1;
        // TODO priority_queue
        for (int i = 0; i < s_nodes.size(); ++i) {
            if (!s_nodes[i].closed && s_nodes[i].time < INT32_MAX) {
                // 是open
                if (cur < 0 || s_nodes[i].time < s_nodes[cur].time) {
                    // 选最快的那个
                    cur = i;
                }
                // 这里不需要选同时最少的那个吗？
            }
        }

        if (cur < 0) {
            // 已经遍历完所有可达的节点
            break;
        }

        for (int next = 0; next < s_adj_len.size(); ++next) {
            if (s_adj_len[cur][next] < 0) {
                continue;
            }

            int new_time = s_nodes[cur].time + s_adj_time[cur][next];
            if (new_time < s_nodes[next].time ||
                (new_time == s_nodes[next].time && s_nodes[cur].count + 1 < s_nodes[next].count)) {
                // 更快或时间相同选最少点
                // 更新路径
                s_nodes[next].time = new_time;
                s_nodes[next].pred = cur;
                s_nodes[next].count = s_nodes[cur].count + 1;
            }
        }

        s_nodes[cur].closed = true;

        if (cur == dest) {
            // 已找到终点，剪枝
            break;
        }
    }

    // 生成最快路径
    int min_time = s_nodes[dest].time;
    deque<int> fastest;
    cur = dest;
    while (cur >= 0) {
        fastest.push_front(cur);
        cur = s_nodes[cur].pred;
    }

    bool eq = false;
    if (shortest.size() == fastest.size()) {
        int i;
        for (i = 0; i < shortest.size(); ++i) {
            if (shortest[i] != fastest[i]) {
                break;
            }
        }

        if (i == shortest.size()) {
            // eq
            eq = true;
        }
    }

    if (eq) {
        printf("Distance = %d; ", min_len);
    } else {
        printf("Distance = %d: ", min_len);
        for (auto iter = shortest.cbegin(); iter != shortest.cend(); ++iter) {
            if (iter != shortest.cbegin()) {
                printf(" -> ");
            }
            printf("%d", *iter);
        }
        printf("\n");
    }

    printf("Time = %d: ", min_time);
    for (auto iter = fastest.cbegin(); iter != fastest.cend(); ++iter) {
        if (iter != fastest.cbegin()) {
            printf(" -> ");
        }
        printf("%d", *iter);
    }
    printf("\n");

    return 0;
}
