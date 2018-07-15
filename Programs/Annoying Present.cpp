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

using namespace std;
typedef long long ll;
typedef std::pair<int, int> pii;




void SOLVE() {

  cout << setprecision(15) << fixed;

  int n, m;
  cin >> n >> m;
  
  ll mincoeffsum = 1e15, maxcoeffsum = -1;
  ll sum = 0;
  
  for (ll i = 0; i < n; ++i) {
    ll t = i*(i+1)/2 + (n-i-1)*(n-i)/2;
    mincoeffsum = min(mincoeffsum, t);
    maxcoeffsum = max(maxcoeffsum, t);
  }
  
  while (m--) {
    int x, d;
    cin >> x >> d;
    sum += n*x;
    if (d > 0) {
      sum += d*maxcoeffsum;
    } else {
      sum += d*mincoeffsum;
    }
  }
  
  double avg = double(sum) / double(n);
  cout << avg;
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






