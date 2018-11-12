#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define all(v) begin(v), end(v)
typedef long long ll;
typedef long double ld;
typedef std::pair<int, int> ii;
typedef std::vector<ii> vii;
typedef std::vector<int> vi;






void Solve() {
  string s;
  cin >> s;

  int n = s.length();
  int ans = 0;
  vi dp(n); // dp[i] = najdolgo 'pola verglanje' (XY) sto zavrsuva ovde

  dp[0] = 0;
  for (int i = 1; i < n; ++i) {
    dp[i] = 0;
    if (s[i] == s[i-1]) {
      dp[i] = 1;
    }
    if (s[i] == s[i - 1 - 2*dp[i-1]]) {
      dp[i] = dp[i-1] + 1;
    }
    if (dp[i - dp[i]] * 2 == dp[i]) {
      ans = max(ans, 2*dp[i]); // celo verglanje
    }
//    cout << "dp[" << i << "] = " << dp[i] << endl;
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
