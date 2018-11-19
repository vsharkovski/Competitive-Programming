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

  vector<ll> a(n+2);
  a[0] = a[n+1] = 0;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
  }
  sort(a.begin()+1, a.end()-1);

  vector<ll> b(n+2), c(n+2);
  b[0] = c[n+1] = 0;
  for (int i = 1; i <= n+1; ++i) {
    b[i] = b[i-1] + a[i];
  }
  for (int i = n; i >= 0; --i) {
    c[i] = c[i+1] + a[i];
  }

//  for (int i = 0; i <= n+1; ++i) {
//    cout << "a[" << i << "]=" << a[i] << "  b[" << i << "]=" << b[i] << "  c[" << i << "]=" << c[i] << "\n";
//  }

  ll ans = c[1];
  for (int i = 1; i <= n-1; ++i) {
    if (b[i+1] > c[i+1]) {
//      cout << "i=" << i << " ==> ";
      if (i+2 <= n+1 && b[i] + c[i+2] >= c[i+1]) {
//        cout << "{1.1}\n";
      } else {
        if (i+2 <= n+1) {
//          cout << "{1.2.1}\n";
          ans += c[i+1] - b[i] - c[i+2];
        } else {
//          cout << "{1.2.2}\n";
          ans += c[i+1] - b[i];
        }
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
