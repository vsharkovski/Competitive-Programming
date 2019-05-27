#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

/*
TASK: barn1
LANG: C++
*/

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    #ifndef _DEBUG
    freopen("barn1.in", "r", stdin);
    freopen("barn1.out", "w", stdout);
    #endif

    int m, s, c;
    cin >> m >> s >> c;

    vector<int> full(c);
    for (int i = 0; i < c; ++i) {
        cin >> full[i];
    }
    sort(full.begin(), full.end());

    vector<int> gaps;
    for (int i = 1; i < c; ++i) {
        gaps.push_back(max(0, full[i] - full[i-1] - 1));
    }
    sort(gaps.begin(), gaps.end());

    int ans = c;
    for (int i = 0; i < c-m; ++i) {
        ans += gaps[i];
    }

    cout << ans << '\n';

}
