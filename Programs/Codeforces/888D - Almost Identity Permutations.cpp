#include <bits/stdc++.h>
using namespace std;
typedef long long ll;





int get_ways(int k) {
    vector<int> v(k);
    for (int i = 0; i < k; ++i) {
        v[i] = i;
    }
    int ans = 0;
    do {
        bool ok = true;
        for (int i = 0; i < k; ++i) {
            if (v[i] == i) {
                ok = false;
                break;
            }
        }
        if (ok) ++ans;
    } while (next_permutation(v.begin(), v.end()));
    return ans;
}

int main() {
    ll n, k;
    cin >> n >> k;
    ll ans = 1;
    if (k >= 2 && n >= 2) {
        ans += (n-1)*n/(1*2);
    }
    if (k >= 3 && n >= 3) {
        ans += (n-2)*(n-1)*(n)/(1*2*3) * get_ways(3);
    }
    if (k >= 4 && n >= 4) {
        ans += (n-3)*(n-2)*(n-1)*(n)/(1*2*3*4) * get_ways(4);
    }
    cout << ans << '\n';
}
