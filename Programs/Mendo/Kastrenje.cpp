#include <bits/stdc++.h>
using namespace std;


int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#ifdef _DEBUG
    freopen("input.txt", "r", stdin);
//  freopen("output.txt", "w", stdout);
#endif

    int n;
    cin >> n;
    map<string, vector<int>> m;
    vector<string> v(n);
    for (int i = 0; i < n; ++i) {
        string s, s1 = "";
        cin >> s;
        v[i] = s;
        for (int j = 0; j < s.length(); ++j) {
            s1 += s[j];
            m[s1].push_back(i);
        }
    }
    for (auto it = m.begin(); it != m.end(); ++it) {
        sort(it->second.begin(), it->second.end());
    }
    for (int i = 0; i < n; ++i) {
        string s1 = "";
        for (int j = 0; j < v[i].length(); ++j) {
            s1 += v[i][j];
            if (m[s1].size() == 1) {
                cout << s1 << '\n';
                break;
            }
        }
    }


}
