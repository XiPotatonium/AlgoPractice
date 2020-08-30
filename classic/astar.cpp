#include <hash_map>
#include <memory>
#include <queue>

using namespace std;

struct AStarNode {
    unsigned int m_index;
    tuple<double, double> m_pos;
    int m_parent;
    double m_g;
    double m_f;

    AStarNode(unsigned int index, tuple<double, double> pos) : m_index(index), m_pos(pos) {
        m_parent = -1;
        m_g = 0;
        m_f = 0;
    }

    bool operator>(const AStarNodeWrapper &b) const { return m_node->m_f > b.m_node->m_f; }

    double h(const AStarNode &end) const {
        double x = get<0>(m_pos);
        double y = get<1>(m_pos);
        double end_x = get<0>(end.m_pos);
        double end_y = get<1>(end.m_pos);
        return abs(x - end_x) + abs(y - end_y);
    }
};

vector<unsigned int> search(vector<tuple<double, double>> pos, vector<vector<double>> mat, unsigned int start,
                            unsigned int end) {
    vector<AStarNode> nodes;
    for (int i = 0; i < pos.size(); ++i) {
        nodes.push_back(AStarNode(i, pos[i]));
    }

    // c++�Դ���priority_queue�ƺ������У�����п����ֶ�bubble��priority_queue��������һ��AStarNodeWrapper���dup������
    priority_queue<AStarNode, vector<AStarNode>, greater<AStarNode>> frontiers;
    frontiers.push(nodes[start]);

    while (!frontiers.empty()) {
        shared_ptr<AStarNode> current = frontiers.top().m_node;
        frontiers.pop();

        if (current->m_index == end) {
            break;
        }

        vector<double> adj = m_mat[current->m_index];
        for (int i = 0; i < adj.size(); ++i) {
            if (adj[i] > 0) {
                // neighbour
                double g = current->m_g + adj[i];
                if (nodes[i].m_parent < 0 || g < nodes[i].m_g) {
                    nodes[i].m_g = g;
                    nodes[i].m_f = nodes[i].m_f + current->h(nodes[end]);
                    nodes[i].m_parent = current->m_index;
                    frontiers.push(nodes[i]); // ����dup�������ڽ��ʱ����ܻ�����⣬��ʱ��Ҳ�ᵼ���ڴ汬ը
                }
            }
        }
    }

    vector<unsigned int> path;
    unsigned int cur = end;
    while (cur >= 0) {
        // TODO ���ɽ�
        cur = m_nodes[cur].m_parent;
    }
    return path;
}

int main(void) { return 0; }