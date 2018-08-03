#include <iostream>
#include <iomanip>
#include <algorithm>
#include <cmath>
#include <complex>
#include <utility>
#include <string>
#include <vector>
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

  int T;
  cin >> T;
  while (T--) {

    int n;
    cin >> n;

    bool flag = 0; // a > b
    int sz = 0;
    int curr = 0, prev = 0;

    for (int i = 1; i <= n; ++i) {
      cin >> curr;
      if (flag ? prev > curr : prev < curr) {
        sz++;
        flag = !flag;
      }
      prev = curr;
    }

    cout << sz << endl;

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
















