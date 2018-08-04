#include <iostream>
#include <iomanip>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <complex>
#include <functional>
#include <utility>
#include <string>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <list>
#include <bitset>
#include <sstream>

#define endl '\n'
#define EPS 1e-9
#define all(v) begin(v), end(v)

using namespace std;
typedef long long ll;
typedef std::pair<int, int> ii;
typedef std::vector<ii> vii;
typedef std::vector<int> vi;





void SOLVE() {

  int n;
  ll m;
  cin >> n >> m;

  vi val(n);
  ll sum = 0;
  for (int i = 0; i < n; ++i) {
    int a, b;
    cin >> a >> b;
    val[i] = a-b;
    sum += a;
  }
  sort(all(val));

  int cnt = 0;
  for (int i = n-1; i >= 0 && sum > m; --i) {
    sum -= val[i];
    ++cnt;
  }
  if (sum > m) {
    cout << -1 << endl;
  } else {
    cout << cnt << endl;
  }
}


int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  #ifdef _DEBUG
  std::freopen("in.txt", "r", stdin);
  std::freopen("out.txt", "w", stdout);
  #endif
  SOLVE();
}




