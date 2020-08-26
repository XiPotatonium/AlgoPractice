/// ��������
/// �����õ��Ǵ��ڽӾ���ķ���
/// DFS���ǲ���ADS����ѧ���ˣ�����DFS������������Ϊvisited�����Ϊvisited��˳������������򡣣�ע�⣬��ֹ��·��Ҫ��preview_visited��
/// BFS�������ö���ά�����Ϊ0�Ľڵ㣨���Կ�����������������Ż���

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
            adj[prerequisites[i][0]][prerequisites[i][0]]++; // �Խ����������
        }

        vector<int> ret(numCourses);
        for (int t = 0; t < numCourses; ++t) {
            for (i = 0; i < numCourses; ++i) {
                if (adj[i][i] == 0) {
                    adj[i][i] = -1;
                    for (int j = 0; j < numCourses; ++j) {
                        if (adj[i][j] == 1) {
                            // �б�
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
}/// ��������
/// �����õ��Ǵ��ڽӾ���ķ���
/// DFS���ǲ���ADS����ѧ���ˣ�����DFS������������Ϊvisited�����Ϊvisited��˳������������򡣣�ע�⣬��ֹ��·��Ҫ��preview_visited��
/// BFS�������ö���ά�����Ϊ0�Ľڵ㣨���Կ�����������������Ż���

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
            adj[prerequisites[i][0]][prerequisites[i][0]]++; // �Խ����������
        }

        vector<int> ret(numCourses);
        for (int t = 0; t < numCourses; ++t) {
            for (i = 0; i < numCourses; ++i) {
                if (adj[i][i] == 0) {
                    adj[i][i] = -1;
                    for (int j = 0; j < numCourses; ++j) {
                        if (adj[i][j] == 1) {
                            // �б�
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