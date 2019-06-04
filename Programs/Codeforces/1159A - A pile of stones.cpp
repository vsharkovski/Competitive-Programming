#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;




int main() {
    ios::sync_with_stdio(false); cin.tie(0);

    int n;
    cin >> n;

    string s;
    cin >> s;

    reverse(s.begin(), s.end());

    for (int ans = 0; ans <= n; ++ans) {
        bool ok = true;
        int bal = ans;
        for (char ch : s) {
            if (ch == '-') {
                ++bal;
            } else {
                --bal;
            }
            if (bal < 0) {
                ok = false;
                break;
            }
        }
        if (ok) {
            cout << ans << '\n';
            return 0;
        }
    }

}
