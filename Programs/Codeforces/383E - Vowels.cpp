#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

void __print(int x) {cerr << x;}
void __print(long x) {cerr << x;}
void __print(long long x) {cerr << x;}
void __print(unsigned x) {cerr << x;}
void __print(unsigned long x) {cerr << x;}
void __print(unsigned long long x) {cerr << x;}
void __print(float x) {cerr << x;}
void __print(double x) {cerr << x;}
void __print(long double x) {cerr << x;}
void __print(char x) {cerr << '\'' << x << '\'';}
void __print(const char *x) {cerr << '\"' << x << '\"';}
void __print(const string &x) {cerr << '\"' << x << '\"';}
void __print(bool x) {cerr << (x ? "true" : "false");}

template<typename T, typename V>
void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ','; __print(x.second); cerr << '}';}
template<typename T>
void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i: x) cerr << (f++ ? "," : ""), __print(i); cerr << "}";}
void _print() {cerr << "]\n";}
template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}
#ifndef ONLINE_JUDGE
#define debug(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define debug(x...)
#endif

const int maxn = 10010;
const int maxb = 24;

int n;
int dp[1<<maxb];

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    cin >> n;
    memset(dp, 0, sizeof(dp));
    for (int i = 0; i < n; ++i) {
        string s;
        cin >> s;
        int m = 0;
        for (char ch : s) {
            m |= (1 << (ch - 'a'));
        }
        ++dp[m];
    }
    for (int i = 0; i < maxb; ++i) {
        for (int m = 0; m < (1<<maxb); ++m) {
            if (m & (1<<i)) {
                dp[m] += dp[m ^ (1<<i)];
            }
        }
    }
    ll ans = 0;
    for (int m = 0; m < (1<<maxb); ++m) {
        int res = n - dp[~m & ((1<<maxb)-1)];
        ans ^= (ll)res * res;
    }
    cout << ans << endl;
}
