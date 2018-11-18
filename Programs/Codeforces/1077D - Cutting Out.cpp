#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define all(v) begin(v), end(v)
typedef long long ll;
typedef long double ld;
typedef std::pair<int, int> ii;
typedef std::vector<ii> vii;
typedef std::vector<int> vi;




int n, k;
map<int, int> cnt;
set<ii, greater<ii>> s;

bool ok(int num) {
  int m = 0;
  for (ii p : s) {
    int c = p.first;
    int r = c / num;
    m += r;
    if (m >= k) return true;
  }
  return false;
}

void Solve() {
  cin >> n >> k;

  for (int i = 0; i < n; ++i) {
    int x;
    cin >> x;
    ++cnt[x];
  }
  for (auto &kvp : cnt) {
    s.emplace(kvp.second, kvp.first);
  }

  int lo = 1, hi = n, mid, res = 1;
  while (lo <= hi) {
    mid = (lo + hi) / 2;
    if (ok(mid)) {
      res = mid;
      lo = mid+1;
    } else {
      hi = mid-1;
    }
  }

//  cout << res <<endl;

  for (ii p : s) {
    int c = p.first;
    for (int r = 1; r <= c && c >= r * res && k > 0; ++r) {
      --k;
      cout << p.second << " ";
    }
    if (k == 0) break;
  }


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
