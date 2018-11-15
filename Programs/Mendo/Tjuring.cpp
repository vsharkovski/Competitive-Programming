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
  map<ll, int> data[62];

  int N;
  cin >> N;
  int maxlen = 0;

  for (int q = 0; q < N; ++q) {
    string s;
    cin >> s;
    int n = s.length();
    for (int i = 0; i < n; ++i) {
      ll x = 0;
      int len = 0;
      for (int j = i; j < min(i+60, n); ++j) {
        ++len;
        x <<= 1;
        if (s[j] == 'b') x |= 1;
        if (q == 0) {
          data[len][x] = 1;
        } else {
          auto it = data[len].find(x);
          if (it != data[len].end()) {
            if (it->second == q) {
              it->second = q+1;
              if (q+1 == N) {
                maxlen = max(len, maxlen);
              }
            } else {
              data[len].erase(it);
            }
          }
        }
      }
    }
  }
  cout << maxlen << endl;
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
