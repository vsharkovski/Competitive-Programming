#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

/*
TASK: beads
LANG: C++
*/

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    freopen("beads.in", "r", stdin);
    freopen("beads.out", "w", stdout);

    int n;
    string s;
    cin >> n >> s;

    int ans = 0;

    for (int start = 0; start < n; ++start) {
        string t = s.substr(start, n-start) + s.substr(0, start);
        int res = 0;
        int i = 0;
        while (i < n && t[i] == 'w') {
            ++res;
            ++i;
        }
        if (i == n) {
            ans = n;
            break;
        }
        char ch1 = t[i];
        while (i < n && (t[i] == ch1 || t[i] == 'w')) {
            ++res;
            ++i;
        }
        int j = n-1;
        while (j >= i && t[j] == 'w') {
            ++res;
            --j;
        }
        if (j >= i) {
            char ch2 = t[j];
            while (j >= i && (t[j] == ch2 || t[j] == 'w')) {
                ++res;
                --j;
            }
        }
        ans = max(ans, res);
    }

    cout << ans << '\n';

}
