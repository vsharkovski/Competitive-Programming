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
  string s;
  cin >> s;
  int n = s.length();
  for (int R = 1; R <= 5; ++R) {
    for (int C = 1; C <= 20; ++C) {
      if (R*C < n) continue;
      int stars = R * C - n;
      char grid[6][22] = {};
      for (int i = 1; stars > 0; ++i) {
        for (int r = 1; r <= R && stars > 0; ++r) {
          grid[r][i] = '*';
          --stars;
        }
      }
      cout << R << " " << C << endl;
      int i = 0;
      for (int r = 1; r <= R; ++r) {
        for (int c = 1; c <= C; ++c) {
          if (grid[r][c] == '*') {
            cout << "*";
          } else {
            cout << s[i];
            ++i;
          }
        }
        cout << endl;
      }
      return;
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
