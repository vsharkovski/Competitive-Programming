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

  int n, a, b;
  cin >> n >> a >> b;
  
  vi v(n);
  for (int i = 0; i < n; ++i) {
    cin >> v[i];
  }
  
  int sum = 0;
  
  if (n & 1) {
    if (v[n/2] == 2) {
      sum += min(a, b);
    }
  }
  for (int i = 0, j = n-1; i < j; ++i, --j) {
    if (v[i] == 0) {
      if (v[j] == 0) continue;
      if (v[j] == 1) { cout << -1; return; }
      v[j] = 0;
      sum += a;
    } else if (v[i] == 1) {
      if (v[j] == 1) continue;
      if (v[j] == 0) { cout << -1; return; }
      v[j] = 1;
      sum += b;
    } else {
      if (v[j] == 0) {
        v[i] = 0;
        sum += a;
      } else if (v[j] == 1) {
        v[i] = 1;
        sum += b;
      } else {
        sum += 2*min(a, b);
      }
    }
  }

  cout << sum << endl;

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












