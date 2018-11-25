#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define all(v) begin(v), end(v)
typedef long long ll;
typedef long double ld;
typedef std::pair<int, int> ii;
typedef std::vector<ii> vii;
typedef std::vector<int> vi;






void Solve() {
  int n;
  cin >> n;

  set<int> s1, s2;
  for (int i = 0; i < 100; ++i) {
    s1.insert(i+1);
  }

  for (int i = 0; i < n; ++i) {
    int r;
    cin >> r;
    for (int j = 0; j < r; ++j) {
      int x;
      cin >> x;
      if (s1.count(x)) {
        s2.insert(x);
      }
    }
    s1 = s2;
    s2.clear();
  }

  for (int x : s1) {
    cout << x << " ";
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
