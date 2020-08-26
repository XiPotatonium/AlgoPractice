/// 这也太烦了
/// 加强版Dijkestra

#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

class City {
public:
    string name;
    int happy = 0;

    bool close = false;
    bool open = false;
    int cost = INT32_MAX;
    vector<int> pred_ids;

    void set_cost(int new_cost, int pred_id) {
        if (new_cost < cost) {
            cost = new_cost;
            pred_ids = vector<int>();
            pred_ids.push_back(pred_id);
        } else if (new_cost == cost) {
            pred_ids.push_back(pred_id);
        }
    }
};

class Solution {
    vector<vector<int>> _adj;
    vector<City> _cities;
    unordered_map<string, int> _dict;
    int _rom_idx;

    vector<vector<int>> _paths;
    vector<int> _buf;
    int _max_happy_path_idx;

    void _gen_path(int idx) {
        _buf.push_back(idx);

        if (idx == 0) {
            _paths.push_back(vector<int>(_buf.size()));
            int new_happy = 0;
            int path_idx = _paths.size() - 1;
            for (int i = 0; i < _buf.size(); ++i) {
                _paths[path_idx][_buf.size() - 1 - i] = _buf[i];
                new_happy += _cities[_buf[i]].happy;
            }
            if (new_happy > happy) {
                _max_happy_path_idx = path_idx;
                happy = new_happy;
            } else if (new_happy == happy) {
                if (_paths[path_idx].size() <
                    _paths[_max_happy_path_idx].size()) {
                    _max_happy_path_idx = path_idx;
                }
            }
        } else {
            for (auto iter = _cities[idx].pred_ids.begin();
                 iter != _cities[idx].pred_ids.end(); ++iter) {
                _gen_path(*iter);
            }
        }
        _buf.erase(--_buf.end());
    }

    void _gen_ans() {
        // 统计
        happy = 0;
        _gen_path(_rom_idx);

        for (auto iter = _paths[_max_happy_path_idx].begin();
             iter != _paths[_max_happy_path_idx].end(); ++iter) {
            best_path.push_back(_cities[*iter].name);
        }
        path_count = _paths.size();
    }

public:
    int min_cost;
    int path_count;
    int happy;
    vector<string> best_path;

    Solution(int n, string start) {
        _adj = vector<vector<int>>(n, vector<int>(n));
        _cities = vector<City>(n);
        _dict.emplace(start, 0);
        _cities[0].name = start;
    }

    void set_city(string name, int happy) {
        int idx = _dict.size();
        _cities[idx].name = name;
        _cities[idx].happy = happy;
        _dict.emplace(_cities[idx].name, idx);
    }

    void set_path(string &c0, string &c1, int cost) {
        auto iter1 = _dict.find(c0);
        auto iter2 = _dict.find(c1);
        _adj[iter1->second][iter2->second] =
            _adj[iter2->second][iter1->second] = cost;
    }

    void solve() {
        int idx = 0;
        _cities[0].open = true;
        _cities[0].cost = 0;

        _rom_idx = _dict.find("ROM")->second;

        while (idx != _rom_idx) {
            _cities[idx].close = true;
            _cities[idx].open = false;
            for (int i = 0; i < _cities.size(); ++i) {
                if (_adj[idx][i] > 0 && !_cities[i].close) {
                    _cities[i].open = true;
                    _cities[i].set_cost(_cities[idx].cost + _adj[idx][i], idx);
                }
            }
            int min_id = -1, min_cost = INT32_MAX;
            for (int i = 0; i < _cities.size(); ++i) {
                if (_cities[i].open && _cities[i].cost < min_cost) {
                    min_cost = _cities[i].cost;
                    min_id = i;
                }
            }
            idx = min_id;
        }

        min_cost = _cities[_rom_idx].cost;
        _gen_ans();
    }
};

int main() {
    int n, k, happy, cost;
    string name, name1;
    cin >> n >> k >> name;

    Solution s(n, name);

    for (int i = 1; i < n; ++i) {
        cin >> name;
        cin >> happy;
        s.set_city(name, happy);
    }

    for (int i = 0; i < k; ++i) {
        cin >> name >> name1;
        cin >> cost;
        s.set_path(name, name1, cost);
    }

    s.solve();

    cout << s.path_count << " " << s.min_cost << " " << s.happy << " "
         << s.happy / (s.best_path.size() - 1) << endl;

    for (auto iter = s.best_path.begin(); iter != s.best_path.end(); ++iter) {
        if (iter != s.best_path.begin()) {
            cout << "->";
        }
        cout << *iter;
    }

    return 0;
}
