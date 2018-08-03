#include <iostream>
#include <iomanip>
#include <algorithm>
#include <cmath>
#include <complex>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <functional>

#define endl '\n'
#define EPS 1e-9

using namespace std;
typedef long long ll;





void SOLVE() {

  int n;
  while (cin >> n, n != 0) {

    vector<int> v(n);
    ll sum = 0;

    for (int i = 0; i < n; ++i) {
      cin >> v[i];
      sum += v[i];
    }

    int starti = 0;
    while (v[starti] == 0 && starti < n)
      starti++;

    if (starti < n) {
      cout << v[starti];
    } else {
      cout << 0;
    }

    for (int i = starti+1; i < n; ++i) {
      if (v[i] > 0) {
        cout << ' ' << v[i];
      }
    }

    cout << endl;

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
