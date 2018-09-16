#include <bits/stdc++.h>
 
#define endl '\n'
#define EPS 1e-9
#define all(v) begin(v), end(v)
 
using namespace std;
typedef long long ll;
typedef long double ld;
typedef std::pair<int, int> ii;
typedef std::vector<ii> vii;
typedef std::vector<int> vi;
 
const ll mod = 1e9 + 7;
template<typename T> T gcd(T a, T b){T c; while(b){c=b; b=a%b; a=c;} return a;}
template<typename T> T powmod(T a, T b){T res = 1; a %= mod; while(b){ if(b&1)res=res*(a%mod); a=a*(a%mod); b>>=1;} return res;}
 









void Solve() {

  int n, m;
  vector<ll> a, b;
  
  ll sum = 0;
  
  cin >> n;
  a.resize(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
    sum += a[i];
  }
  
  cin >> m;
  b.resize(m);
  for (int i = 0; i < m; ++i) {
    cin >> b[i];
    sum -= b[i];
  }
  
  if (sum != 0) {
    cout << -1; return;
  }
  
  int ans = 0;
  int i = 0, j = 0;
  while (i < n) {
    ++ans;
    ll ca = a[i++], cb = b[j++];
    while (ca != cb) {
      if (ca < cb) ca += a[i++];
      else         cb += b[j++];
    }
  }

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








