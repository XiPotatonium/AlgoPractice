/// ��ȫ������������������������м�ڵ㣨�Һ����ǿգ�֮�����еĽڵ㶼��Ҷ�ӽڵ�
/// �ٿ����и��ٷ��Ķ��壬�����Ǹ������ƺ���ǰ������ϱȽϺ��á�

#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main(void) {
    int n;
    cin >> n;

    vector<int> left(n);
    vector<int> right(n);
    vector<bool> mentioned(n);

    string s;
    for (int i = 0; i < n; ++i) {
        cin >> s;
        if (s == "-") {
            left[i] = -1;
        } else {
            left[i] = atoi(s.c_str());
            mentioned[left[i]] = true;
        }

        cin >> s;
        if (s == "-") {
            right[i] = -1;
        } else {
            right[i] = atoi(s.c_str());
            mentioned[right[i]] = true;
        }
    }

    int root = 0;
    for (; root < n; ++root) {
        if (!mentioned[root]) {
            break;
        }
    }

    queue<int> q;
    q.push(root);
    int last_node = -1;

    while (!q.empty()) {
        int cur = q.front();

        if (left[cur] == -1) {
            if (right[cur] == -1) {
                last_node = q.back();
            } else {
                // ���Һ���û�����Ӳ���Complete
                last_node = -1;
                break;
            }
        } else if (right[cur] == -1) {
            if (last_node >= 0) {
                // �Ѿ�����Ҷ�ӽڵ������������ӵĽڵ㣬����complete
                last_node = -1;
                break;
            } else {
                last_node = left[cur];
            }
        } else if (last_node >= 0) {
            // �Ѿ�����Ҷ�ӽڵ������������Һ��ӵĽڵ㣬����complete
            last_node = -1;
            break;
        }

        if (left[cur] != -1) {
            q.push(left[cur]);
        }
        if (right[cur] != -1) {
            q.push(right[cur]);
        }

        // �ŵ�����pop���������ֻ��һ���ڵ�
        q.pop();
    }

    if (last_node >= 0) {
        printf("YES %d\n", last_node);
    } else {
        printf("NO %d\n", root);
    }

    return 0;
}