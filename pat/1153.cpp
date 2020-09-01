/// 类似数据库
/// 有一说一，哈希真滴快

#include <algorithm>
#include <cstring>
#include <iostream>
#include <memory>
#include <unordered_map>
#include <vector>

using namespace std;

struct Card {
    string id;
    int score;

    Card(string &&id, int score) : id(id), score(score) {}

    int get_site() { return (id[1] - '0') * 100 + (id[2] - '0') * 10 + (id[3] - '0'); }
};

bool card_pred(const unique_ptr<Card> &a, const unique_ptr<Card> &b) {
    if (a->score == b->score) {
        return a->id < b->id;
    } else {
        return a->score > b->score;
    }
}

struct Site {
    int site_id;
    int cnt;

    Site(int id, int cnt) : site_id(id), cnt(cnt) {}
};

bool site_pred(const Site &a, const Site &b) {
    if (a.cnt == b.cnt) {
        return a.site_id < b.site_id;
    } else {
        return a.cnt > b.cnt;
    }
}

int main(void) {
    int n, m, score;
    cin >> n >> m;
    vector<unique_ptr<Card>> data(n);

    string id, term;
    for (int i = 0; i < n; ++i) {
        cin >> id >> score;
        data[i] = unique_ptr<Card>(new Card(std::move(id), score));
    }

    sort(data.begin(), data.end(), card_pred);

    int qtype, nt, ns;
    bool empty_res;
    unordered_map<int, int> site_cnt_map;
    vector<Site> sites;
    for (int iquery = 0; iquery < m; ++iquery) {
        cin >> qtype >> term;
        printf("Case %d: %d %s\n", iquery + 1, qtype, term.c_str());
        empty_res = true;
        switch (qtype) {
        case 1:
            for (auto &iter : data) {
                if (iter->id[0] == term[0]) {
                    printf("%s %d\n", iter->id.c_str(), iter->score);
                    empty_res = false;
                }
            }
            break;
        case 2:
            nt = ns = 0;

            for (auto &iter : data) {
                if (strncmp(iter->id.c_str() + 1, term.c_str(), 3) == 0) {
                    ++nt;
                    ns += iter->score;
                }
            }

            empty_res = nt == 0;

            if (!empty_res) {
                printf("%d %d\n", nt, ns);
            }

            break;
        case 3:
            site_cnt_map.clear();
            sites.clear();

            for (auto &iter : data) {
                if (strncmp(iter->id.c_str() + 4, term.c_str(), 6) == 0) {
                    ++site_cnt_map[iter->get_site()];
                    empty_res = false;
                }
            }

            for (auto &site_kv : site_cnt_map) {
                sites.emplace_back(site_kv.first, site_kv.second);
            }
            sort(sites.begin(), sites.end(), site_pred);

            for (auto &site : sites) {
                printf("%d %d\n", site.site_id, site.cnt);
            }

            break;

        default:
            break;
        }

        if (empty_res) {
            printf("NA\n");
        }
    }

    return 0;
}