#include <bits/stdc++.h>
#define endl '\n'
typedef long long ll;
using namespace std;




void _initialize();
int main() {
  _initialize();

  bool first = 1;
  int k;
  while (cin >> k) {

    if (k == 0) {
      break;
    }
    if (first) {
      first = 0;
    } else {
      cout << endl;
    }

    int a[k];
    for (int i = 0; i < k; ++i) {
      cin >> a[i];
    }

    for (int q = 0; q < k; ++q) {
      for (int w = q+1; w < k; ++w) {
        for (int e = w+1; e < k;++e) {
          for (int r = e+1; r < k; ++r) {
            for (int t = r+1; t < k; ++t) {
              for (int y = t+1; y < k; ++y) {
                cout << a[q] << ' ' << a[w] << ' ' << a[e] << ' ' << a[r] << ' ' << a[t] << ' ' << a[y] << endl;
              }
            }
          }
        }
      }
    }

  }




}




void _initialize() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  #ifdef _DEBUG
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
  #endif
}
