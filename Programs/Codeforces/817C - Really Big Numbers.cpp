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




ll n, s;

inline bool ok(ll x) {
  int sum = 0;
  ll y = x;
  while (y) {
    sum += y % 10;
    y /= 10;
  }
  return x - sum >= s;
}

void Solve() {
  cin >> n >> s;
  ll lo = max(1, (int)s - 157), hi = n+1, mid;
  ll best = 0;
  while (lo <= hi) {
    mid = (lo + hi) / 2;
    if (ok(mid)) {
      best = mid;
      hi = mid-1;
    } else {
      lo = mid+1;
    }
  }
//  cout << best << " " << n << endl;
  if (best > 0) cout << n - best + 1 << endl;
  else cout << 0 << endl;
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








