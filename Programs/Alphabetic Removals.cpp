#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;



int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    bool atend[n];
    memset(atend, 1, sizeof(atend));
    vector<vector<int>> data(26);
    for (int i = 0; i < n; ++i) {
        data[s[i]-'a'].push_back(i);
    }
    for (int i = 0; i < 26 && k > 0; ++i) {
        for (int j = 0; j < data[i].size() && k > 0; ++j) {
            atend[data[i][j]] = 0;
            k--;
        }
    }
    for (int i = 0; i < n; ++i) {
        if (atend[i]) {
            cout << s[i];
        }
    }

}
