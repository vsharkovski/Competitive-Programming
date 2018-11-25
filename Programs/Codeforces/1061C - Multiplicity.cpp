#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define all(v) begin(v), end(v)
typedef long long ll;
typedef long double ld;
typedef std::pair<int, int> ii;
typedef std::vector<ii> vii;
typedef std::vector<int> vi;



const ll mod = 1e9 + 7;

void Solve() {
  int n;
  cin >> n;

  int a[100005] = {};
  vector<ll> cnt(1000005, 0);

  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
  }
  cnt[0] = 1;
  for (int i = 1; i <= n; ++i) {
    int x = a[i];
//    cout << "for i=" << i <<" (x=" << x << ") :\n";
    for (int d = sqrt(x); d >= 1; --d) {
      if (x % d == 0) {
        cnt[x/d] += cnt[x/d - 1];
        cnt[x/d] %= mod;
//        cout << "  " << x/d << " divides " << x << " ==> cnt[" << x/d << "] = " << cnt[x/d] << " ; ";
        if (d * d != x) {
          cnt[d] += cnt[d - 1];
          cnt[d] %= mod;
//          cout << "cnt[" << d << "] = " << cnt[d];
        }
//        cout << endl;
      }
    }
  }
  ll ans = 0;
  for (int i = 1; i <= n+1; ++i) {
    ans += cnt[i];
    ans %= mod;
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
