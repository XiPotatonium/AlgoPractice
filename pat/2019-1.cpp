#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

string s_vocab[26][7];

void print(vector<char> &word) {
    for (int i = 0; i < 7; ++i) {
        for (int j = 0; j < word.size() && j < 10; ++j) {
            if (j != 0) {
                cout << ' ';
            }
            cout << s_vocab[word[j] - 'A'][i];
        }
        cout << endl;
    }
}

int main(void) {
    for (int i = 0; i < 26; ++i) {
        for (int j = 0; j < 7; ++j) {
            cin >> s_vocab[i][j];
        }
    }

    bool has_prev = false;
    string s;

    cin.ignore();
    getline(cin, s);

    vector<char> word;
    int i;
    for (i = 0; i < s.size(); ++i) {
        if (s[i] >= 'A' && s[i] <= 'Z') {
            word.push_back(s[i]);
        } else if (word.size() > 0) {
            if (has_prev) {
                cout << endl;
            } else {
                has_prev = true;
            }
            print(word);
            word = vector<char>();
        }
    }

    // mgj
    if (i == s.size() && word.size() > 0) {
        if (has_prev) {
            cout << endl;
        } else {
            has_prev = true;
        }
        print(word);
    }

    return 0;
}