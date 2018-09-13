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
 
 
 
 
 
 
 
 
 
int m, n, u, d, l;

inline int go(int x, int y) {
  return x < y ? (y-x)*u : (x-y)*d;
}

void Solve() {
  cin >> m >> n >> u >> d >> l;
  int lm = 1e7, ln = 1e7;
  for (int i = 0; i < l; ++i) {
    int h;
    cin >> h;
    if (go(m, lm) > go(m, h)) lm = h;
    if (go(ln, n) > go(h, n)) ln = h;
  }
  int ans = min(go(m, n), go(m, lm) + go(ln, n));
  cout << ans << endl;
//  cout << "lm=" << lm << " ln=" << ln << " ln->n = " << go(ln, n) << endl;
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








