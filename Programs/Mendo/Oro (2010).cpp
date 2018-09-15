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
 





int M, N; // 0 <= p <= M
int G[55]; // |G| = N

int dp[55][1005];
int f(int i, int p) {
  if (p < 0 || p > M) return -1;
  if (i == N) return p;
  if (dp[i][p] != -1) return dp[i][p];
  return dp[i][p] = max(f(i+1, p - G[i]), f(i+1, p + G[i]));
}

void Solve() {
  int p;
  cin >> p >> M >> N;
  for (int i = 0; i < N; ++i) {
    cin >> G[i];
  }
  memset(dp, -1, sizeof(dp));
  cout << f(0, p) << endl;
  
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








