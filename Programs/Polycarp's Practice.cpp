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
const int G_V = 1, G_U = -1; //graph visited constant, graph unvisited constant






void SOLVE() {

  int n, k;
  cin >> n >> k;
  
  vi a(n);
  vii b(n);
  for (int i = 0; i < n; ++i) {
    cin >> b[i].first;
    b[i].second = i;
    a[i] = b[i].first;
  }
  
  sort(b.begin(), b.end(), [](ii &x, ii &y) {
    return x.first > y.first;
  });

  b.erase(b.begin()+k, b.end());
  
  int sum = 0;
  for (int i = 0; i < b.size(); ++i) sum += b[i].first;
  
  sort(b.begin(), b.end(), [](ii &x, ii &y) {
    return x.second < y.second;
  });
  
  b[b.size()-1].second = n-1;
  
  cout << sum << endl;
  
  int prev = 0;
  for (int i = 0; i < b.size(); ++i) {
    cout << b[i].second - prev + 1 << ' ';
    prev = b[i].second + 1;
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




