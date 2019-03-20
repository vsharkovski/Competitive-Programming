#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pi;
typedef vector<int> vi;



const ll SZ = 1000005;

int N;
ll A;
vector<int> insertion[SZ];
int ft[SZ];

void update(int k, int x) {
    for (; k <= SZ; k += k & -k) {
        ft[k] += x;
    }
}

int query(int k) {
    int res = 0;
    for (; k >= 1; k -= k & -k) {
        res += ft[k];
    }
    return res;
}

int query(int a, int b) {
    return query(b) - query(a-1);
}

void Main() {
    cin >> N >> A;
    for (int i = 0; i < N; ++i) {
        int x, y;
        cin >> x >> y;
        insertion[x].push_back(y);
    }
    memset(ft, 0, sizeof(ft));
    int ans = 0;
    for (ll x = 1; x <= 1e6; ++x) {
        for (int y : insertion[x]) {
            update(y, 1);
        }
        ll y = A/x;
        ans = max(ans, query(1, min(SZ, y)));
    }
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    #ifdef _DEBUG
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
    #endif
    Main();
    return 0;
}
