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
  int T;
  cin >> T;
  while (T--) {

    string s;
    cin >> s;
    int n = s.length();

    bool has[1000002] = {};
    for (int i = 0; i < n; ++i) {
      int x = 0;
      for (int j = i; j < min(i + 6, n); ++j) {
        x = 10*x + (s[j] - '0');
        has[x] = 1;
      }
    }

    for (int x = 0; x <= 1000000; ++x) {
      if (has[x] == 0) {
        cout << x << endl;
        break;
      }
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
  Solve();
}
