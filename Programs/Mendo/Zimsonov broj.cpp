#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pi;
typedef vector<int> vi;




void Main() {
    int L, R;
    cin >> L >> R;
    int ans = 0;
    for (int x = L; x <= R; ++x) {
        string s = to_string(x);
        bool ok = true;
        for (int i = 0, j = s.length() - 1; i < j; ++i, --j) {
            if (s[i] != s[j]) {
                ok = false;
                break;
            }
        }
        if (ok) {
            ++ans;
            continue;
        }
        ok = true;
        int y = x;
        while (y > 0) {
            int d = y % 10;
            y /= 10;
            if (d == 0 || x % d != 0) {
                ok = false;
                break;
            }
        }
        if (ok) {
            ++ans;
        }
    }
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    #ifndef _DEBUG
    #endif
    Main();
    return 0;
}
