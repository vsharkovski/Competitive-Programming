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

#define endl '\n'
#define EPS 1e-9

using namespace std;
typedef long long ll;
typedef std::pair<int, int> pii;


void SOLVE() {

  int n, m;
  cin >> n >> m;
  vector<int> v(m);
  for (int i = 0; i < m; ++i) {
    cin >> v[i];
  }
  sort(v.begin(), v.end());
  int mini = 2e9;
  for (int i = 0; i+n-1 < m; ++i) {
    mini = min(mini, v[i+n-1] - v[i]);
  }
  cout << mini << endl;



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












