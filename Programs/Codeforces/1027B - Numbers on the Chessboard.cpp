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
  ll n, q;
  cin >> n >> q;
  ll m = ceil((long double)(n)*0.5*(long double)(n));
  while (q--) {
    ll x, y;
    cin >> x >> y;
    ll ans = n*(x-1) + y;
    if (ans % 2 == 1) ++ans;
    ans /= 2;
    if ((x + y) % 2 == 1) ans += m;
    cout << ans << endl;
//    cout << " for (" << x << "," << y << ")" << endl;
  }
  



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
