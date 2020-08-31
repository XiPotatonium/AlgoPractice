// 这题也是中等？

#include <iostream>
#include <vector>

using namespace std;

class Solution {
    vector<bool> ans;

    void dfs(int id, const vector<vector<int>> &rooms) {
        ans[id] = true;

        for (int key : rooms[id]) {
            if (!ans[key]) {
                dfs(key, rooms);
            }
        }
    }

public:
    bool canVisitAllRooms(vector<vector<int>> &rooms) {
        ans = vector<bool>(rooms.size());

        dfs(0, rooms);

        for (auto i : ans) {
            if (!i) {
                return false;
            }
        }
        return true;
    }
};

int main(void) {

    Solution s;

    vector<vector<int>> rooms = {{1}, {2}, {3}, {}};

    cout << s.canVisitAllRooms(rooms) << endl;

    return 0;
}
