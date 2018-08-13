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



int n;
ll a[5005];
ll dp[5005];

inline ll sum(int i, int j) {
  return dp[j] - dp[i];
}

void Solve() {
  cin >> n;
  cin >> a[0];
  dp[0] = 0;
  for (int i = 1; i < n; ++i) {
    cin >> a[i];
    dp[i] = dp[i-1] + a[i-1];
  }
  dp[n] = dp[n-1] + a[n-1];

  ll f0 = 0, f1 = 0, f2 = 0, maxi = -7e17;

  for (int d1 = 0; d1 <= n; ++d1) {
    ll x = 0, bd0 = 0, y = 0, bd2 = 0;
    for (int d0 = 0; d0 <= d1; ++d0) {
      ll curr = sum(0, d0) - sum(d0, d1);
      if (curr > x) {
        x = curr;
        bd0 = d0;
      }
    }
    for (int d2 = d1; d2 <= n; ++d2) {
      ll curr = sum(d1, d2) - sum(d2, n);
      if (curr > y) {
        y = curr;
        bd2 = d2;
      }
    }
    ll curr = x+y;
    if (curr > maxi) {
      maxi = curr;
      f0 = bd0;
      f1 = d1;
      f2 = bd2;
    }
  }

  cout << f0 << " " << f1 << " " << f2 << endl;


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








