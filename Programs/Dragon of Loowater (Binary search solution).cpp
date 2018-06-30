#include <bits/stdc++.h>
#define endl '\n'
#define EPS 1e-9
typedef long long ll;
using namespace std;

// Binary search solution

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
    sort(knights.begin(), knights.end());

    int cnt = 0;

    for (int d : heads) {
      auto it = lower_bound(knights.begin(), knights.end(), d);
      if (it == knights.end()) {
        cnt = -1;
        break;
      }
      cnt += *it;
      knights.erase(it);
    }

    if (cnt == -1) {
      cout << "Loowater is doomed!\n";
    } else {
      cout << cnt << endl;
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
