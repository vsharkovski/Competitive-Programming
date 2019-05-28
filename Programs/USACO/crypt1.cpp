#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

/*
TASK: crypt1
LANG: C++
*/

bool valid(vector<bool>& ok, int len, int x) {
    int xlen = 0;
    while (x > 0) {
        ++xlen;
        if (ok[x % 10] == false) {
            return false;
        }
        x /= 10;
    }
    return xlen == len;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    #ifndef _DEBUG
    freopen("crypt1.in", "r", stdin);
    freopen("crypt1.out", "w", stdout);
    #endif

    vector<bool> ok(10, false);
    vector<int> digits;

    int n;
    cin >> n;
    while (n--) {
        int x;
        cin >> x;
        ok[x] = true;
        digits.push_back(x);
    }

    int ans = 0;

    for (int a : digits) {
        for (int b : digits) {
            for (int c : digits) {
                for (int d : digits) {
                    for (int e : digits) {
                        int abc = 100*a + 10*b + c;
                        int de = 10*d + e;
                        if (valid(ok, 3, e*abc) && valid(ok, 3, d*abc) && valid(ok, 4, de*abc)) {
                            ++ans;
                        }
                    }
                }
            }
        }
    }

    cout << ans << '\n';

}
