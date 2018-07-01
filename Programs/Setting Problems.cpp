#include <bits/stdc++.h>
#define endl '\n'
#define EPS 1e-9
typedef long long ll;
using namespace std;


void solve() {

  int n;

  while (cin >> n) {

    vector<pair<int, int>> a(n);
    int ans = 1e9;

    for (int i = 0; i < n; ++i) {
      cin >> a[i].first;
    }
    for (int i = 0; i < n; ++i) {
      cin >> a[i].second;
    }

    sort(a.begin(), a.end(), [](pair<int, int> &q, pair<int, int> &w) -> bool {
      if (q.first < q.second && w.first < w.second) {
        return q.first < w.first;
      } else if (q.first < q.second && w.first > w.second) {
        return 1;
      } else if (q.first > q.second && w.first < w.second) {
        return 0;
      } else {
        // q.first > q.second && w.first > w.second;
        return q.second > w.second;
      }
    });

    int gt = 0, st = 0;
    for (int i = 0; i < n; ++i) {
      gt += a[i].first;
      st = max(gt, st) + a[i].second;
    }

    cout << st << endl;

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
