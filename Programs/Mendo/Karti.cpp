#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define all(v) begin(v), end(v)
typedef long long ll;
typedef long double ld;
typedef std::pair<int, int> ii;
typedef std::vector<ii> vii;
typedef std::vector<int> vi;





int probaj(int n, int k, vi a, bool t) {
  int res = 0;
  queue<int> q;
  for (int i = 0; i < n; ++i) {
    if (!q.empty() && i == q.front()) {
      q.pop();
      t = !t;
    }
    if (a[i] != t) {
      if (i + k > n) {
        return 1e9;
      } else {
        q.push(i + k);
        t = !t;
        ++res;
      }
    }
  }
  return res;
}

void Solve() {
  int n, k;
  cin >> n >> k;

  vi a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }

  int t1 = probaj(n, k, a, 0);
  int t2 = probaj(n, k, a, 1);

  if (t1 == 1e9 && t2 == 1e9) {
    cout << -1;
  } else {
    cout << min(t1, t2) << endl;
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
