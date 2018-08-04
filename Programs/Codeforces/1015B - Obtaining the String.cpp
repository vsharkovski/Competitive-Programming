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
  cin >> n;
  int nchs[200] = {}, ncht[200] = {};
  string s, t;
  cin >> s >> t;
  for (char ch : s) ++nchs[ch];
  for (char ch : t) ++ncht[ch];
  for (int i = 0; i < 200; ++i) {
    if (nchs[i] != ncht[i]) {
      cout << -1;
      return;
    }
  }
  int k = 0;
  vi seq;
  for (int i = 0; i < n; ++i) {
    if (s[i] != t[i]) {
      int j = i+1;
      while (t[i] != s[j] && j < n) ++j;
      while (j > i) {
        seq.push_back(j-1);
        swap(s[j-1], s[j]);
        ++k;
        --j;
      }
    }
  }
  if (s != t) {
    cout << -1;
    return;
  }
  cout << k << endl;
  for (int x : seq) {
    cout << x+1 << ' ';
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







