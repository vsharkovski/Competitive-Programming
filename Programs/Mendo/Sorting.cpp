#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define all(v) begin(v), end(v)
typedef long long ll;
typedef long double ld;
typedef std::pair<int, int> ii;
typedef std::vector<ii> vii;
typedef std::vector<int> vi;






int gcd(int a, int b) {
  return b == 0 ? a : gcd(b, a%b);
}

int n;
int a[500005];

// key: a[i] -> a[a[i]] iff |a[i]-i| mod x == 0
// so compute gcd of all differences
// answer is all divisors of that

void Solve() {
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
  }
  int g = abs(a[1] - 1);
  for (int i = 2; i <= n; ++i) {
    g = gcd(g, abs(a[i] - i));
  }
  vector<int> ans;
  for (int d = 1; d <= g; ++d) {
    if (g % d == 0) {
      ans.push_back(d);
    }
  }
  cout << ans.size() << endl;
  for (int x : ans) cout << x << " ";


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
