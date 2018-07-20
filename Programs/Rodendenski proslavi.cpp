#include <iostream>
#include <iomanip>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <complex>
#include <utility>
#include <string>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <functional>
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
const int UNVISITED = -1, VISITED = 0;





void SOLVE() {

  int n;
  cin >> n;
  
  bool data[13][32];
  memset(data, 0, sizeof(data));
  
  vii ans(13);
  ans[0] = ii(0, -1);
  
  for (int i = 0; i < n; ++i) {
    int d, m;
    cin >> d >> m;
    if (data[m][d] == 0) {
      ++ans[m].second;
      data[m][d] = 1;
    }
  }
  
  for (int i = 1; i <= 12; ++i) {
    ans[i].first = i;
  }
  
  sort(ans.begin(), ans.end(), [](ii &x, ii &y) {
    return x.second > y.second;
  });
  
  vi ans2;
  
  int prev = -1;
  for (int i = 0; i < 12; ++i) {
    if (ans[i].second < prev) break;
    ans2.push_back(ans[i].first);
    prev = ans[i].second;
  }
  
  sort(ans2.begin(), ans2.end());
  
  for (int x : ans2) {
    cout << x << '\n';
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
