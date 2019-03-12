#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pi;
typedef vector<int> vi;






void Main() {
    int n, m;
    cin >> n >> m;
    vector<int> p(n+1);
    vector<set<int>> data(n+1, set<int>());
    for (int i = 0; i < n; ++i) {
        cin >> p[i];
    }
    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        data[a].insert(b);
    }
    set<int> s;
    s.insert(p[n-1]);
    int ans = 0;
    for (int i = n-2; i >= 0; --i) {
        bool canbepassedbyall = true;
        for (int x : s) {
            if (data[p[i]].count(x) == 0) {
                canbepassedbyall = false;
                break;
            }
        }
        if (canbepassedbyall) {
            ++ans;
        } else {
            s.insert(p[i]);
        }
    }
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    Main();
    return 0;
}
