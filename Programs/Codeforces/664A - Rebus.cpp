#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;




inline int getmin(int n, int pos, int neg) {
    return pos*1 - neg*n;
}

inline int getmax(int n, int pos, int neg) {
    return pos*n - neg*1;
}

int main() {
//    ios::sync_with_stdio(false); cin.tie(0);

    int n;
    vector<int> signs;
    int pos = 0, neg = 0;

    char ch;
    cin >> ch;
    ++pos;
    signs.push_back(1);
    while (cin >> ch) {
        if (ch == '=') {
            cin >> n;
            break;
        } else {
            int sgn;
            if (ch == '+') {
                ++pos;
                sgn = 1;
            } else {
                ++neg;
                sgn = -1;
            }
            signs.push_back(sgn);
            cin >> ch;
        }
    }

    if (n < getmin(n, pos, neg) || n > getmax(n, pos, neg)) {
        cout << "Impossible\n";
        return 0;
    }

    cout << "Possible\n";

    int sum = 0;

    for (int idx = 0; idx < (int)signs.size(); ++idx) {
        int sgn = signs[idx];
        if (idx > 0) {
            cout << (sgn == 1 ? '+' : '-') << ' ';
        }
        if (sgn == 1) {
            --pos;
        } else {
            --neg;
        }
        int lo = 1, hi = n, x, fx = 1e9;
        while (lo <= hi) {
            x = (lo + hi) / 2;
            int minposs = sum + sgn*x + getmin(n, pos, neg);
            int maxposs = sum + sgn*x + getmax(n, pos, neg);
            if (minposs > n) {
                // sgn*x is too big
                if (sgn == 1) {
                    hi = x-1;
                } else {
                    lo = x+1;
                }
            } else if (maxposs < n) {
                // sgn*x is too small
                if (sgn == 1) {
                    lo = x+1;
                } else {
                    hi = x-1;
                }
            } else {
                fx = x;
                break;
            }
        }
        cout << fx << ' ';
        sum += sgn*fx;
    }

    cout << "= " << n << '\n';

}
