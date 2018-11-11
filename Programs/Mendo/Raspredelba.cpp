#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define all(v) begin(v), end(v)
typedef long long ll;
typedef long double ld;
typedef std::pair<int, int> ii;
typedef std::vector<ii> vii;
typedef std::vector<int> vi;



int ans;

void bruteforce(vi a, vi b, int steps) {
  vi tmp(10), c;
  sort(a.begin(), a.end());
  sort(b.begin(), b.end());
  c = a;
  a = vi(tmp.begin(), set_difference(a.begin(), a.end(), b.begin(), b.end(), tmp.begin()));
  b = vi(tmp.begin(), set_difference(b.begin(), b.end(), c.begin(), c.end(), tmp.begin()));
  // a and b are disjoint
  if (a.empty() || b.empty()) {
    ans = min(ans, steps);
    return;
  }
  reverse(a.begin(), a.end());
  reverse(b.begin(), b.end());
  if (a[0] < b[0]) swap(a, b);
  for (int i = 0; i < 3 && i < min(a.size(), b.size()); ++i) {
    if (a[0] <= b[i]) break;
    if (i > 0 && b[i] == b[i-1]) continue;
    vi a1 = a, b1 = b;
    a1[0] -= b1[i];
    b1.erase(b1.begin() + i);
    bruteforce(a1, b1, steps + 1);
  }
}

void Solve() {
  int N, M, sum1 = 0, sum2 = 0;

  cin >> N;
  vi a(N);
  for (int i = 0; i < N; ++i) {
    cin >> a[i];
    sum1 += a[i];
  }

  cin >> M;
  vi b(M);
  for (int i = 0; i < M; ++i) {
    cin >> b[i];
    sum2 += b[i];
  }

  if (sum1 != sum2) {
    cout << "-1\n";
    return;
  }

  ans = 1e9;
  bruteforce(a, b, 0);
  cout << ans << endl;
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
