#include <bits/stdc++.h>
#define endl '\n'
#define EPS 1e-9
typedef long long ll;
using namespace std;



void solve() {

  int T;
  cin >> T;
  while (T--) {

    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
      cin >> a[i];
    }
    sort(a.begin(), a.end());

    stringstream events;
    int t = 0;
    while (n >= 4) {
      int t1 = a[1] + a[0] + a[n-1] + a[1];
      int t2 = a[n-1] + a[0] + a[n-2] + a[0];
      if (t1 < t2) {
        t += t1;
        events << a[0] << " " << a[1] << endl
               << a[0] << endl
               << a[n-1] << " " << a[n-2] << endl
               << a[1] << endl;
      } else {
        t += t2;
        events << a[0] << " " << a[n-1] << endl
               << a[0] << endl
               << a[0] << " " << a[n-2] << endl
               << a[0] << endl;
      }
      n -= 2;
    }
    if (n == 1) {
      t += a[0];
      events << a[0] << endl;
    } else if (n == 2) {
      t += a[1];
      events << a[0] << " " << a[1] << endl;
    } else if (n == 3) {
      t += a[2] + a[0] + a[1];
      events << a[0] << " " << a[2] << endl
             << a[0] << endl
             << a[0] << " " << a[1] << endl;
    }

    cout << t << endl << events.str();
    if (T > 0) cout << endl;

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
