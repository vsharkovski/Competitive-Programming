#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pi;
typedef vector<int> vi;






int M;
vector<ll> h, a;

int N;
vector<ll> dp, tree;

void update(int k, ll x) {
    k += N;
    tree[k] = x;
    for (k /= 2; k >= 1; k /= 2) {
        tree[k] = max(tree[2*k], tree[2*k+1]);
    }
}

ll query(int a, int b, int k, int x, int y) {
    if (b < x || a > y) return 0;
    if (a <= x && y <= b) return tree[k];
    int d = (x + y) / 2;
    return max(query(a, b, 2*k, x, d), query(a, b, 2*k+1, d+1, y));
}

void Main() {
    cin >> M;
    h.resize(M);
    a.resize(M);
    for (int i = 0; i < M; ++i) {
        cin >> h[i];
        --h[i];
    }
    for (int i = 0; i < M; ++i) {
        cin >> a[i];
    }
    N = 1;
    while (N < M) N *= 2;
    tree.assign(2*N, 0);
    dp.assign(M, 0);
    ll ans = 0;
    // dp[i] = a[i] + max(dp[j]) for every j < i, h[j] < h[i]
    for (int i = 0; i < M; ++i) {
        dp[i] = a[i] + query(0, h[i] - 1, 1, 0, N-1);
        ans = max(ans, dp[i]);
        update(h[i], dp[i]);
    }
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    Main();
}
