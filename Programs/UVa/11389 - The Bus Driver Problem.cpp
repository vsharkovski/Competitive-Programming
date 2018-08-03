#include <bits/stdc++.h>
#define endl '\n'
#define EPS 1e-9
typedef long long ll;
using namespace std;



void solve() {

  int n, d, r;
  while (cin >> n >> d >> r, n != 0 && d != 0 && r != 0) {

    vector<int> a(n), b(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    for (int i = 0; i < n; ++i) cin >> b[i];
    sort(a.begin(), a.end());
    sort(b.begin(), b.end(), greater<int>());

    int t = 0;

    for (int i = 0; i < n; ++i) {
      int c = a[i] + b[i];
      if (c > d) {
        t += r*(c-d);
      }
    }

    cout << t << endl;


  }

}


int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  #ifdef _DEBUG
  std::freopen("in.txt", "r", stdin);
  std::freopen("out.txt", "w", stdout);
  #endif
  solve();
}
