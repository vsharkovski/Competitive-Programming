#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;



ll gcd(ll a, ll b) {
    return b == 0 ? a : gcd(b, a % b);
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    ll a, b, x, y;
    cin >> a >> b >> x >> y;
    ll g = gcd(x, y);
    x /= g, y /= g;
    ll k = min(a/x, b/y);
    ll n = a - k*x, m = b - k*y;
    cout << a-n << ' ' << b-m << '\n';
}
