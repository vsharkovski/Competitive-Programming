#include <bits/stdc++.h>
#define endl '\n'
#define EPS 1e-9
typedef long long ll;
using namespace std;



void solve() {

  int n;

  while (cin >> n, n != 0) {

    vector<int> v(n);
    map<int, int> counts;
    int m = 0;

    for (int i = 0; i < n; ++i) {
      cin >> v[i];
      m = max(m, ++counts[v[i]]);
    }
    sort(v.begin(), v.end());

    int grid[m][n] = {}; // m rows, n cols

    int xi = n-1;
    for (int j = 0; j < n && xi >= 0; ++j) {
      for (int i = 0; i < m && xi >= 0; ++i) {
        grid[i][j] = v[xi];
        xi--;
      }
    }

    cout << m << endl;
    for (int i = 0; i < m; ++i) {
      cout << grid[i][0];
      for (int j = 1; j < n; ++j) {
        if (grid[i][j] == 0) break;
        cout << ' ' << grid[i][j];
      }
      cout << endl;
    }

    cout << endl;

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
