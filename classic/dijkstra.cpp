#include <iostream>
#include <vector>

using namespace std;

struct Node {
    int pred;
    int dist;
    bool is_closed;
};

vector<vector<int>> s_adj;
vector<Node> s_nodes;

/// <summary>
/// 单源最短路径
/// </summary>
/// <param name="src"></param>
void dij(int src) {
    for (Node &node : s_nodes) {
        node.dist = INT32_MAX;
        node.is_closed = false;
        node.pred = -1;
    }
    s_nodes[src].dist = 0;

    for (;;) {
        int cur = -1;
        // 找open中最近的那一个，可以用最小堆优化
        for (int i = 0; i < s_nodes.size(); ++i) {
            if (!s_nodes[i].is_closed && s_nodes[i].dist < INT32_MAX) {
                // open
                if (cur == -1 || s_nodes[i].dist < s_nodes[cur].dist) {
                    cur = i;
                }
            }
        }

        if (cur == -1) {
            // 遍历完毕
            break;
        }

        for (int next = 0; next < s_adj[cur].size(); ++next) {
            if (s_adj[cur][next] < 0) {
                continue;
            }

            int new_dist = s_nodes[cur].dist + s_adj[cur][next];
            if (new_dist < s_nodes[next].dist) {
                s_nodes[next].dist = new_dist;
                s_nodes[next].pred = cur;
            }
        }

        s_nodes[cur].is_closed = true;
    }
}

int main(void) {

    // 1. 建图

    // 2. 搜索

    // 3. 构造答案，比如path

    return 0;
}