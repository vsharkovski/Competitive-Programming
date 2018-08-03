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


int n;
ll a[25][25];

ll f(int i, int j) {
  ll& ref = a[i][j];
  if (ref != -1) return ref;
  
  ref = 0;
  
  if (i < j) {
    for (int k = i; k < j; ++k) {
      ref = max(ref, f(i, k) + f(k+1, j));
    }
    return ref;
  }
  
  for (int k = i+1; k <= n; ++k) {
    ref = max(ref, f(k, 1) + f(k, j));
  }
    
  ll temp = 0;
  for (int k = 1; k < j; ++k) {
    temp = max(temp, f(i, k) + f(n, k));
  }
  ref += temp;
  
  return ref;
}



void SOLVE() {

  int x;
  while (cin >> n >> x) {
    
    memset(a, -1, sizeof(a));
    a[n][1] = x;
    cout << f(1, n) << endl;
    
  
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



















