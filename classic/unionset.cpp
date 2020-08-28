#include <iostream>
#include <vector>

using namespace std;

class UnionSet {
    vector<int> father;
public:
    UnionSet(int n) : father(n) {
        for(int i = 0; i < father.size(); ++i) {
            father[i] = i;
        }
    }

    int find_root(int x) {
        int tail = x;
        while (father[x] != x) {
            x = father[x];
        }
        int root = x;
        // 路径压缩
        x = tail;
        while (root != x) {
            int f = father[x];
            father[x] = root;
            x = f;
        }
        return root;
    }
};

int main(void) {

    return 0;
}