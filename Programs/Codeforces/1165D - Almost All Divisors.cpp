#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;



int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        vector<ll> divs;
        for (int i = 0; i < n; ++i) {
            ll d;
            cin >> d;
            divs.emplace_back(d);
        }
        sort(divs.begin(), divs.end());
        ll x = divs[0] * divs[n-1];
        vector<ll> realdivs;
        for (ll i = 2; i*i <= x; ++i) {
            if (x % i == 0) {
                if (i*i == x) {
                    realdivs.emplace_back(i);
                } else {
                    realdivs.emplace_back(i);
                    realdivs.emplace_back(x/i);
                }
            }
        }
        sort(realdivs.begin(), realdivs.end());
        if (divs == realdivs) {
            cout << x << '\n';
        } else {
            cout << "-1\n";
        }
    }
}
