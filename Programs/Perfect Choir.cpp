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


void SOLVE();
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  #ifdef _DEBUG
  std::freopen("in.txt", "r", stdin);
  std::freopen("out.txt", "w", stdout);
  #endif
  SOLVE();
}






void SOLVE() {

  int n;
  while (cin >> n) {

    vector<int> v(n);
    int avg = 0.0;

    for (int i = 0; i < n; ++i) {
      int x;
      cin >> x;
      v[i] = x;
      avg += x;
    }

    if (avg % n != 0) {
      cout << -1 << endl;
      continue;
    }
    avg /= n;
    sort(v.begin(), v.end());

    int bars = 1, j = n-1;

    for (int i = 0; i < n; ++i) {
      if (v[i] >= avg) break;
      int x = avg - v[i];
      bars += x;
      while (x > 0 && j >= 0 && v[j] > avg) {
        int y = v[j] - avg;
        if (x >= y) {
          x -= y;
          j--;
        } else {
          v[j] -= x;
          x = 0;
        }
      }
    }

    cout << bars << endl;

  }


}



























