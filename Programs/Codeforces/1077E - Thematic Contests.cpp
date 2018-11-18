#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define all(v) begin(v), end(v)
typedef long long ll;
typedef long double ld;
typedef std::pair<int, int> ii;
typedef std::vector<ii> vii;
typedef std::vector<int> vi;





int n;
map<int, int> m;
vector<int> v;
int ans = 1;

void Solve() {
  cin >> n;
  for (int i = 0; i < n; ++i) {
    int x;
    cin >> x;
    ++m[x];
  }
  for (auto &kvp : m) {
    v.push_back(kvp.second);
  }
  sort(v.begin(), v.end(), greater<int>());
  n = v.size();
  for (int x = 1; x <= v[0]; ++x) {
    int total = x;
    int i = 1;
    int y = x; //start from biggest element
    while (i < n && y % 2 == 0) {
      y /= 2;
      if (v[i] < y) break; // all elements after this are also smaller (v is sorted)
      //take from i-th element
      total += y;
      ++i;
    }
    ans = max(ans, total);
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
