#include <algorithm>
#include <iostream>
#include <memory>
#include <unordered_map>
#include <vector>

using namespace std;

struct Institution {
    string id;
    int ns;
    double tws;
    int itws;

    Institution(string &id) : id(id) {
        ns = itws = 0;
        tws = 0;
    }
};

bool pred(const unique_ptr<Institution> &a, const unique_ptr<Institution> &b) {
    if (a->itws == b->itws) {
        if (a->ns == b->ns) {
            return a->id < b->id;
        } else {
            return a->ns < b->ns;
        }
    } else {
        return a->itws > b->itws;
    }
}

int main(void) {

    unordered_map<string, unique_ptr<Institution>> inst_map;
    int n, score;
    string id, school;

    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> id >> score >> school;

        for (auto &ch : school) {
            ch = tolower(ch);
        }

        auto iter = inst_map.find(school);
        if (iter == inst_map.end()) {
            inst_map.emplace(school, unique_ptr<Institution>(new Institution(school)));
            iter = inst_map.find(school);
        }

        iter->second->ns += 1;
        switch (id[0]) {
        case 'B':
            iter->second->tws += (double)score / 1.5;
            break;
        case 'A':
            iter->second->tws += (double)score;
            break;
        case 'T':
            iter->second->tws += (double)score * 1.5;
            break;
        }
    }

    vector<unique_ptr<Institution>> insts;

    for (auto &i : inst_map) {
        i.second->itws = i.second->tws;
        insts.emplace_back(std::move(i.second));
    }

    sort(insts.begin(), insts.end(), pred);

    cout << insts.size() << endl;
    int rank = 0, last_tws = -1;
    for (int i = 0; i < insts.size(); ++i) {
        if (insts[i]->itws != last_tws) {
            rank = i + 1;
            last_tws = insts[i]->itws;
        }
        printf("%d %s %d %d\n", rank, insts[i]->id.c_str(), insts[i]->itws, insts[i]->ns);
    }

    return 0;
}
