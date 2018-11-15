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

  int ans = 0;
  for (int i = 0; i < n; ++i) {
    if (s[i] == 'Y') {
      ++ans;
      for (int j = i; j < n; j += i+1) {
        s[j] = s[j] == 'Y' ? 'N' : 'Y';
      }
    }
  }

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
