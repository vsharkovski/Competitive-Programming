#include <bits/stdc++.h>

#define endl '\n'
#define EPS 1e-9
#define all(v) begin(v), end(v)

using namespace std;
typedef long long ll;
typedef std::pair<int, int> ii;
typedef std::vector<ii> vii;
typedef std::vector<int> vi;

const ll mod = 998244353;
template<typename T> T gcd(T a, T b){T c; while(b){c=b; b=a%b; a=c;} return a;}
template<typename T> T powmod(T a, T b){T res = 1; a %= mod; while(b){ if(b&1)res=res*(a%mod); a=a*(a%mod); b>>=1;} return res;}




void Solve() {

  int n;
  int p[52], total[52];
  int dp[52];

  cin >> n;
  if (n == 1) { int x; cin >> x; cout << 0 << " " << x << endl; return; }

  for (int i = 0; i < n; ++i) {
    cin >> p[i];
  }
  total[n-1] = p[n-1];
  for (int i = n-2; i >= 0; --i) {
    total[i] = p[i] + total[i+1];
  }

  dp[n-1] = p[n-1];
  for (int i = n-2; i >= 0; --i) {
    dp[i] = max(p[i] - dp[i+1] + total[i+1], dp[i+1]);
  }

  cout << total[0] - dp[0] << " " << dp[0] << endl;

//  for (int i = n-1; i >= 0; --i) {
//    cout << "p[" << i << "]=" << p[i] << " total[" << i << "]=" << total[i] << " dp[" << i << "]=" << dp[i] << endl;
//  }



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








