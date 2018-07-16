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



int n, k;
vi a(505);

void SOLVE() {

  cin >> n >> k;
  
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  
  int ans = 0;
  
  for (int i = 1; i < n; i += 1) {
    int x =  k - (a[i-1] + a[i]);
    if (x <= 0) continue;
    //a[i-1] + a[i] = k;
    a[i] += x;
    ans += x;
  }
  
  cout << ans << endl;
  for (int i = 0; i < n; ++i) {
    cout << a[i] << ' ';
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















