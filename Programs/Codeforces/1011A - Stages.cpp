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








void SOLVE() {

  int n, k;
  string s;
  cin >> n >> k >> s;

  sort(all(s));
  
  if (k == 1) {
    cout << s[0] - 'a' + 1;
    return;
  }
  
  int m = 0, w = 0;
  int prev = -100;
  for (int i = 0; i < n && m < k; ++i) {
    if (s[i] >= prev + 2) {
      ++m;
      int c = s[i] - 'a' + 1;
      w += c;
//      cout << "taking " << s[i] <<  " c=" << c << '\n';
      prev = s[i];
    }
    if (m == k) break;
  }
  
  if (m == k) {
    cout << w << '\n';
  } else {
    cout << -1 << endl;
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




