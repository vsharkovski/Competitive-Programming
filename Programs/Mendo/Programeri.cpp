#include <bits/stdc++.h>
 
#define endl '\n'
#define EPS 1e-9
#define all(v) begin(v), end(v)
 
using namespace std;
typedef long long ll;
typedef std::pair<int, int> ii;
typedef std::vector<ii> vii;
typedef std::vector<int> vi;
 
 
const ll mod = 1e9 + 7;
template<typename T> T gcd(T a, T b){T c; while(b){c=b; b=a%b; a=c;} return a;}
template<typename T> T powmod(T a, T b){T res = 1; a %= mod; while(b){ if(b&1)res=res*(a%mod); a=a*(a%mod); b>>=1;} return res;}
 
 
 
void Solve() {
 
    int n, k;
    cin >> n >> k;
    map<int, ll> m;
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        ++m[x];
    }
    ll ans = 0;
    for (auto it = m.begin(); it != m.end(); ++it) {
        auto it2 = m.find(it->first + k);
        if (it2 != m.end()) {
            if (k == 0) {
                ans += it->second * (it->second - 1) / 2;
            } else {
                ans += it->second * it2->second;
            }
        }
    }
    cout << ans << endl;
 
//    cout << m.begin()->first << " : " << m.begin()->second << endl;
 
 
}
 
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  Solve();
}
