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

  int n;
  cin >> n;

  vector<int> a(n); //1=LL, 2=DD, 3=DL
  for (int i = 0; i < n; ++i) {
    char c1, c2;
    cin >> c1 >> c2;
    a[i] = (c1 == 'L' ? 1 : 2) | (c2 == 'L' ? 1 : 2);
  }

  ll ans = 0;
  int f1 = n, f2 = n;

  for (int i = 0; i < n; ++i) {
    if (a[i] == 1) {
      if (f2 < i) {
        ans += i - f2;
        a[f2] = a[i] = 3;
        while (f2 < i && a[f2] != 2) ++f2;
        if (f2 == i) f2 = n;
      } else if (f1 == n) {
        f1 = i;
      }
    } else if (a[i] == 2) {
      if (f1 < i) {
        ans += i - f1;
        a[f1] = a[i] = 3;
        while (f1 < i && a[f1] != 1) ++f1;
        if (f1 == i) f1 = n;
      } else if (f2 == n) {
        f2 = i;
      }
    }
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
