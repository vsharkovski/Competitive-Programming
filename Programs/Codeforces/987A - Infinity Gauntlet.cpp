#include <bits/stdc++.h>
using namespace std;



int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
//#ifdef _DEBUG
//	freopen("input.txt", "r", stdin);
////	freopen("output.txt", "w", stdout);
//#endif

    int n;
    cin >> n;
    map<string, pair<string, bool>> m;
    m["purple"].first = "Power";
    m["purple"].second = 0;
    m["green"].first = "Time";
    m["green"].second = 0;
    m["blue"].first = "Space";
    m["blue"].second = 0;
    m["orange"].first = "Soul";
    m["orange"].second = 0;
    m["red"].first = "Reality";
    m["red"].second = 0;
    m["yellow"].first = "Mind";
    m["yellow"].second = 0;
    for (int i = 0; i < n; ++i) {
        string c;
        cin >> c;
        m[c].second = 1;
    }
    cout << 6 - n << '\n';
    for (auto it = m.begin(); it != m.end(); ++it) {
        if (it->second.second == 0) {
            cout << it->second.first << '\n';
        }
    }
}
