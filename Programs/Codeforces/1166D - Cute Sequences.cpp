#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;



int possible(ll n, ll a, ll b, ll m) {
    if (a > b) {
        return 1;
    }
    if (n == 1) {
        if (a == b) {
            return 0;
        } else {
            return -1;
        }
    }
    if (n == 2) {
        if (a + m >= b) {
            return 0;
        } else {
            return -1;
        }
    }
    ll pow2 = (1LL<<(n-2));
    ll X = pow2*(a+1);
    ll Y = pow2*(a+m);
    // If overflow, too big anyway
    if (X / (a+1) != pow2 || Y / (a+m) != pow2) {
        return 1;
    }
    if (b < X) {
        return 1;
    } else if (b > Y) {
        return -1;
    } else {
        return 0;
    }
}

void construct(ll n, ll a, ll b, ll m) {
//    cout << "construct(n=" << n << ", a=" << a << ", b=" << b << ", m=" << m << ")\n";
    ll L = 1, R = m, MID, best_r = 0;
    if (n == 2) {
        best_r = b - a;
    } else {
        while (L <= R) {
            MID = (L + R) / 2; // MID = r[i]
            int res = possible(n-1, 2*a + MID, b, m);
            if (res == 0) {
                best_r = MID;
                R = MID-1;
            } else if (res == -1) {
                L = MID+1;
            } else {
                R = MID-1;
            }
        }
    }
//    cout << "best_r=" << best_r << "\n";
//    cout << "result=" << a + best_r << "\n";
    cout << a + best_r << " ";
    if (n > 2) {
        construct(n-1, 2*a + best_r, b, m);
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int Q;
    cin >> Q;
    while (Q--) {
        ll a, b, m;
        cin >> a >> b >> m;
        if (a == b) {
            cout << "1 " << a << '\n';
            continue;
        }
        if (a + m >= b) {
            cout << "2 " << a << " " << b << '\n';
            continue;
        }
        bool done = false;
        for (ll n = 3; n <= 50; ++n) {
            int res = possible(n, a, b, m);
            if (res == 0) {
                cout << n << " " << a << " ";
//                cout << "\n";
                construct(n, a, b, m);
                cout << "\n";
                done = true;
                break;
            }
        }
        if (done == false) {
            cout << "-1\n";
        }
    }
}
