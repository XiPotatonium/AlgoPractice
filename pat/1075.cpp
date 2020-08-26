/// Rank
/// 注意Rank和Count的区别

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

#define UNCOMMIT -2
#define UNCOMPILE -1

vector<int> full_scores;

struct User {
    int id;
    vector<int> scores;
    int total_score = 0;
    bool can_print = false;

    void init(int user_id, int problem_count) {
        id = user_id;
        scores = vector<int>(problem_count);
        for (int i = 0; i < problem_count; ++i) {
            scores[i] = UNCOMMIT;
        }
    }

    void set_score(int pid, int score) {
        if (scores[pid] == UNCOMMIT || scores[pid] == UNCOMPILE) {
            scores[pid] = score;
            if (score >= 0) {
                total_score += score;
                can_print = true;
            }
        } else {
            if (score > scores[pid]) {
                total_score = total_score - scores[pid] + score;
                scores[pid] = score;
            }
        }
    }
};

bool pred(const User &a, const User &b) {
    if (a.total_score == b.total_score) {
        int pa = 0, pb = 0;
        for (int i = 0; i < full_scores.size(); ++i) {
            if (a.scores[i] == full_scores[i]) {
                ++pa;
            }
            if (b.scores[i] == full_scores[i]) {
                ++pb;
            }
        }
        if (pa == pb) {
            return a.id < b.id;
        } else {
            return pa > pb;
        }
    } else {
        return a.total_score > b.total_score;
    }
}

int main(void) {
    int n, k, m;
    scanf("%d %d %d", &n, &k, &m);
    full_scores = vector<int>(k);
    for (int i = 0; i < k; ++i) {
        scanf("%d", &full_scores[i]);
    }

    vector<User> users(n);
    for (int i = 0; i < n; ++i) {
        users[i].init(i + 1, k);
    }

    int uid, pid, score;
    for (int i = 0; i < m; ++i) {
        scanf("%d %d %d", &uid, &pid, &score);
        users[uid - 1].set_score(pid - 1, score);
    }

    sort(users.begin(), users.end(), pred);

    int rank = 0, count = 0, last_score = -100;
    for (auto iter = users.begin(); iter != users.end(); ++iter) {
        if (iter->can_print) {
            count++;
            if (last_score != iter->total_score) {
                rank = count;
                last_score = iter->total_score;
            }
            printf("%d %05d %d", rank, iter->id, iter->total_score);
            for (int i = 0; i < k; ++i) {
                if (iter->scores[i] == UNCOMMIT) {
                    printf(" -");
                } else if (iter->scores[i] == UNCOMPILE) {
                    printf(" 0");
                } else {
                    printf(" %d", iter->scores[i]);
                }
            }
            printf("\n");
        }
    }

    return 0;
}