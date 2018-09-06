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






int n;
ll x, y;

void Solve() {  
  cin >> n >> x >> y;
  vector<ll> dp(n+5, 1e17);
  dp[0] = 0;
  dp[1] = x;
  dp[2] = min(dp[1] + y, dp[1] + x);
  for (int m = 3; m <= n+3; ++m) {
    dp[m] = dp[m-1] + x;
    if (m % 2 == 0) {
      dp[m] = min(dp[m], dp[m/2] + y);
    } else {
      dp[m] = min(dp[m], dp[m/2] + y + x);
      dp[m] = min(dp[m], dp[m/2 + 1] + y + x);
    }
  }
  cout << dp[n] << endl;

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


















