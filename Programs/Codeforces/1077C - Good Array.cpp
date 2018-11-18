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

  vector<ll> a(n);
  map<ll, int> s;
  ll sum = 0;

  for (int i = 0; i < n; ++i) {
    cin >> a[i];
    sum += a[i];
    s[2*a[i]]++;
  }

  vector<ll> ans;
  for (int i = 0; i < n; ++i) {
    if (s[sum - a[i]] > (3*a[i] == sum)) {
//      cout << "sum=" << sum << " ai=" << a[i] << " sum-ai=" << sum-a[i] << endl;
      ans.push_back(i);
//      cout << "found\n";
    }
  }

  cout << ans.size() << endl;
  for (int x : ans) cout << x+1 << " ";

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
