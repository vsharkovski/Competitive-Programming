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

  int n, k;
  cin >> n >> k;

  int atleast = 0;
  int a[100005];
  bool exists[1 << 4] = {};

  for (int i = 0; i < n; ++i) {
    int m = 0;
    for (int j = k-1; j >= 0; --j) {
      int b;
      cin >> b;
      if (b) m |= (1 << j);
    }
    exists[m] = 1;
    if (m == 0) {
      // 0000
      cout << "YES\n";
      return;
    }
  }

  // 1100 and 0011 -> yes
  for (int x = 0; x < (1 << k); ++x) {
    for (int y = 0; y < (1 << k); ++y) {
      if (exists[x] && exists[y] && ((x & y) == 0)) {
        cout << "YES\n";
        return;
      }
    }
  }

  cout << "NO\n";







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





