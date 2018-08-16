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

  int n;
  cin >> n;
  ll s = 0;
  int a = -1e9, b = 1e9;
  for (int i = 0; i < n; ++i) {
    int x;
    cin >> x;
    if (x > 0) s += x;
    if (x & 1) {
      if (x > 0) b = min(b, x);
      if (x < 0) a = max(a, x);
    }
  }
  if (s % 2 == 0) {
    s -= min(-a, b);
  }
  cout << s << endl;




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








