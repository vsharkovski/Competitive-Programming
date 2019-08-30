#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll inf = 1e14;

struct Item {
    int c, f, v, type;
    Item(int c, int f, int v, int type) :
        c(c), f(f), v(v), type(type) {}
    bool operator < (const Item& other) const {
        return f != other.f ? f > other.f : type < other.type;
    }
};

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int n, m, sumc = 0;
    vector<Item> items;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        int c, f, v;
        cin >> c >> f >> v;
        sumc += c;
        items.emplace_back(c, f, v, 0);
    }
    cin >> m;
    for (int i = 0; i < m; ++i) {
        int c, f, v;
        cin >> c >> f >> v;
        sumc += c;
        items.emplace_back(c, f, v, 1);
    }
    sort(items.begin(), items.end());
    vector<ll> dp(sumc + 1, -inf);
    dp[0] = 0;
    for (auto& item : items) {
        if (item.type == 0) {
            // computer
            for (int c = sumc; c >= item.c; --c) {
                dp[c] = max(dp[c], dp[c - item.c] - item.v);
            }
        } else {
            // order
            for (int c = 0; c <= sumc - item.c; ++c) {
                dp[c] = max(dp[c], dp[c + item.c] + item.v);
            }
        }
    }
    ll ans = -inf;
    for (int c = 0; c <= sumc; ++c) {
        ans = max(ans, dp[c]);
    }
    cout << ans << endl;
}
