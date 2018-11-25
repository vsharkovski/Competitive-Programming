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
  int S;
  cin >> n >> S;
  int cnt = 0;
  for (int i = min(n, S); i >= 0 && S > 0; --i) {
    int k = S / i;
    cnt += k;
    S %= i;
  }
  cout << cnt << endl;

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
