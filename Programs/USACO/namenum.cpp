#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

/*
TASK: namenum
LANG: C++
*/

vector<char> dict[200];

inline bool okay(char a, char b) {
    return find(dict[a].begin(), dict[a].end(), b) != dict[a].end();
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);

    dict['2'] = {'A', 'B', 'C'};
    dict['3'] = {'D', 'E', 'F'};
    dict['4'] = {'G', 'H', 'I'};
    dict['5'] = {'J', 'K', 'L'};
    dict['6'] = {'M', 'N', 'O'};
    dict['7'] = {'P', 'R', 'S'};
    dict['8'] = {'T', 'U', 'V'};
    dict['9'] = {'W', 'X', 'Y'};

    ifstream in("namenum.in");
    string seq;
    in >> seq;

    ofstream out("namenum.out");

    int n = seq.length();
    int num_printed = 0;

    ifstream dictfile("dict.txt");
    string word;
    while (getline(dictfile, word)) {
        if (word.length() != seq.length()) {
            continue;
        }
        bool good = true;
        for (int i = 0; i < n; ++i) {
            if (okay(seq[i], word[i]) == false) {
                good = false;
                break;
            }
        }
        if (good) {
            ++num_printed;
            out << word << '\n';
        }
    }

    if (num_printed == 0) {
        out << "NONE\n";
    }
}
