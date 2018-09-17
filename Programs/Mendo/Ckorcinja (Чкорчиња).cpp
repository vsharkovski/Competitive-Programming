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
 
    int m;
    cin >> m;
 
    int d[10] = {6, 3, 5, 5, 4, 5, 5, 3, 7, 5};
 
    int cnt[10000] = {};
    int ans = -1;
 
    for (int x = 0; x <= 9999; ++x) {
        string s = to_string(x);
        for (char ch : s) {
            cnt[x] += d[ch-'0'];
        }
        if (cnt[x] == m) {
            ans = x;
        }
    }
 
    if (ans < 1000) ans = -1;
    cout << ans << endl;
 
 
 
}
 
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  #ifdef _DEBUG
  std::freopen("in.txt", "r", stdin);
  std::freopen("out.txt", "w", stdout);
  #endif
  Solve();
}
