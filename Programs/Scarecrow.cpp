#include <bits/stdc++.h>
#define endl '\n'
#define EPS 1e-9
typedef long long ll;
using namespace std;



void solve() {

  int T;
  cin >> T;
  for (int TT = 1; TT <= T; ++TT) {

    int n;
    cin >> n;
    int a[n+4];
    a[n] = a[n+1] = a[n+2] = 2;
    for (int i = 0; i < n; ++i) {
      char ch;
      cin >> ch;
      a[i] = ch == '#' ? 1 : 0;
    }
    int cnt = 0;
    for (int i = 0; i < n; ++i) {
      if (a[i] == 0) {
        a[i] = a[i+1] = a[i+2] = 2;
        cnt++;
      }
    }
    cout << "Case " << TT << ": " << cnt << endl;

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
