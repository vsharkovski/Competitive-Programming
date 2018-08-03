#include <bits/stdc++.h>
#define endl '\n'
#define EPS 1e-9
typedef long long ll;
using namespace std;


// Greedy solution


void solve() {

  int n, m;
  while (cin >> n >> m, n != 0 && m != 0) {

    vector<int> heads(n), knights(m);
    for (int i = 0; i < n; ++i) {
      cin >> heads[i];
    }
    for (int i = 0; i < m; ++i) {
      cin >> knights[i];
    }
    sort(heads.begin(), heads.end());
    sort(knights.begin(), knights.end());

    int coins = 0;
    int di = 0;
    int ki = 0;
    // for each head with diameter D, find the knight
    // with height H[i] so that H[i-1] < D <= H[i]
    while (di < n && ki < m) {
      while (heads[di] > knights[ki] && ki < m) {
        ++ki;
      }
      if (ki == m) break;
      coins += knights[ki];
      di++;
      ki++;
    }

    if (di == n) {
      cout << coins << endl;
    } else {
      cout << "Loowater is doomed!\n";
    }

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
