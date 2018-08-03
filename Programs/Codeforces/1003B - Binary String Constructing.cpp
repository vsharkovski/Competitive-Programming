#include <iostream>
#include <iomanip>
#include <algorithm>
#include <cstring>
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

  int a, b, x;
  cin >> a >> b >> x;

  int n = a+b;
  int prev = -1;

  if (x == 1) {
    while (a--) {
      cout << 0;
    }
    while (b--) {
      cout << 1;
    }
    return;
  }

  for (int i = 0; i < n; ++i) {
    if (prev == -1) {
      if (a > b) {
        cout << 0;
        --a;
        prev = 0;
      } else {
        cout << 1;
        --b;
        prev = 1;
      }
    } else if (x > 1) {
      if (prev == 0) {
        cout << 1;
        --b;
        prev = 1;
      } else {
        cout << 0;
        --a;
        prev = 0;
      }
      --x;
    } else if (x == 1) {
      if (prev == 0) {
        if (a > 0) {
          cout << 0;
          --a;
        } else {
          cout << 1;
          --b;
          prev = 1;
        }
      } else {
        if (b > 0) {
          cout << 1;
          --b;
        } else {
          cout << 0;
          --a;
          prev = 0;
        }
      }
    } else {
      if (a == 0) {
        cout << 1;
        --b;
      } else if (b == 0) {
        cout << 0;
        --a;
      } else if (prev == 0) {
        cout << 0;
        --a;
      } else {
        cout << 1;
        --b;
      }
    }

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














