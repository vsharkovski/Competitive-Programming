#include <bits/stdc++.h>

#define endl '\n'
#define EPS 1e-9
#define all(v) begin(v), end(v)

using namespace std;
typedef long long ll;
typedef std::pair<int, int> ii;
typedef std::vector<ii> vii;
typedef std::vector<int> vi;

const int mod = 1e9 + 7;
template<typename T> T gcd(T a, T b){T c; while(b){c=b; b=a%b; a=c;} return a;}
template<typename T> T powmod(T a, T b){T res = 1; a %= mod; while(b){ if(b&1)res=res*(a%mod); a=a*(a%mod); b>>=1;} return res;}




void Solve() {

  int n, h, a, b, k;
  cin >> n >> h >> a >> b >> k;

  while (k--) {
    int ta, tb, fa, fb;
    cin >> ta >> fa >> tb >> fb;
    if (fa > fb) swap(fa, fb);
    if (ta > tb) swap(ta, tb);
    int ans = 0;
    if (ta == tb) {
      cout << abs(fa - fb)<<endl;
      continue;
    }
    if (fa < a) {
      ans += a - fa;
      fa = a;
    } else if (fa > b) {
      ans += fa - b;
      fa = b;
    }
    ans += tb - ta;
    if (fa < fb) {
      ans += fb - fa;
    } else if (fa > fb) {
      ans += fa - fb;
    }
    cout << ans << endl;
  }


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




