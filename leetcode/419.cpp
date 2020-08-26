// �ǵݼ�������
// �����ֻ��15
// �������Ҫ���Ǳ���������ȥ��
// �ٷ�����ڽ��ȥ��(�������ַ���hash�ķ�ʽȥ��)��
// �������һ����̬�滮�����������ÿ���ȥ��

#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {

public:
    vector<vector<int>> findSubsequences(vector<int> &nums) {
        // ��key��β�����зǵ����Ӵ�
        unordered_map<int, vector<vector<int>>> table;
        for (int num : nums) {
            vector<vector<int>> vs;
            vs.push_back({num}); // �������ֵ�һ���ڵ�һ��

            // Ѱ�����н�β<=num���Ӵ���append
            for (auto &kv : table) {
                if (kv.first <= num) {
                    for (auto &v : kv.second) {
                        vector<int> newv = v;
                        newv.push_back(num); // ��Ȼappend���������ֻѡ��һ������������Բ������ظ�
                        vs.push_back(std::move(newv));
                    }
                }
            }

            table.insert_or_assign(num, std::move(vs));
        }

        vector<vector<int>> ret;
        for (auto &kv : table) {
            for (int i = 1; i < kv.second.size(); ++i) {
                ret.push_back(std::move(kv.second[i]));
            }
        }
        return ret;
    }
};

int main() {
    vector<int> input = {4, 6, 7, 7};
    Solution s;
    auto vs = s.findSubsequences(input);

    for (auto &v : vs) {
        for (auto item : v) {
            cout << item << " ";
        }
        cout << endl;
    }

    return 0;
}