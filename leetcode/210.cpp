/// 拓扑排序
/// 这里用的是纯邻接矩阵的方法
/// DFS（是不是ADS里面学过了？），DFS遍历，后序标记为visited，标记为visited的顺序就是逆拓扑序。（注意，防止环路，要有preview_visited）
/// BFS，就是用队列维持入度为0的节点（可以看作现在这个方法的优化）

#include <iostream>
#include <queue>
#include <vector>

using namespace std;

class Solution {
private:
public:
    vector<int> findOrder(int numCourses, vector<vector<int>> &prerequisites) {
        vector<vector<int>> adj(numCourses, vector<int>(numCourses));
        int i = 0;
        for (i = 0; i < numCourses; ++i) {
            adj[i].reserve(numCourses);
        }
        for (i = 0; i < numCourses; ++i) {
            for (int j = 0; j < numCourses; ++j) {
                adj[i][j] = 0;
            }
        }
        for (i = 0; i < prerequisites.size(); ++i) {
            adj[prerequisites[i][1]][prerequisites[i][0]] = 1;
            adj[prerequisites[i][0]][prerequisites[i][0]]++; // 对角线上是入度
        }

        vector<int> ret(numCourses);
        for (int t = 0; t < numCourses; ++t) {
            for (i = 0; i < numCourses; ++i) {
                if (adj[i][i] == 0) {
                    adj[i][i] = -1;
                    for (int j = 0; j < numCourses; ++j) {
                        if (adj[i][j] == 1) {
                            // 有边
                            adj[j][j]--;
                        }
                    }
                    ret[t] = i;
                    break;
                }
            }
            if (i == numCourses) {
                return vector<int>();
            }
        }
        return ret;
    }
};

int main(void) {

    Solution s;
    vector<vector<int>> v = {{1, 0}};
    vector<int> res = s.findOrder(2, v);

    return 0;
}/// 拓扑排序
/// 这里用的是纯邻接矩阵的方法
/// DFS（是不是ADS里面学过了？），DFS遍历，后序标记为visited，标记为visited的顺序就是逆拓扑序。（注意，防止环路，要有preview_visited）
/// BFS，就是用队列维持入度为0的节点（可以看作现在这个方法的优化）

#include <iostream>
#include <queue>
#include <vector>

using namespace std;

class Solution {
private:
public:
    vector<int> findOrder(int numCourses, vector<vector<int>> &prerequisites) {
        vector<vector<int>> adj(numCourses, vector<int>(numCourses));
        int i = 0;
        for (i = 0; i < numCourses; ++i) {
            adj[i].reserve(numCourses);
        }
        for (i = 0; i < numCourses; ++i) {
            for (int j = 0; j < numCourses; ++j) {
                adj[i][j] = 0;
            }
        }
        for (i = 0; i < prerequisites.size(); ++i) {
            adj[prerequisites[i][1]][prerequisites[i][0]] = 1;
            adj[prerequisites[i][0]][prerequisites[i][0]]++; // 对角线上是入度
        }

        vector<int> ret(numCourses);
        for (int t = 0; t < numCourses; ++t) {
            for (i = 0; i < numCourses; ++i) {
                if (adj[i][i] == 0) {
                    adj[i][i] = -1;
                    for (int j = 0; j < numCourses; ++j) {
                        if (adj[i][j] == 1) {
                            // 有边
                            adj[j][j]--;
                        }
                    }
                    ret[t] = i;
                    break;
                }
            }
            if (i == numCourses) {
                return vector<int>();
            }
        }
        return ret;
    }
};

int main(void) {

    Solution s;
    vector<vector<int>> v = {{1, 0}};
    vector<int> res = s.findOrder(2, v);

    return 0;
}