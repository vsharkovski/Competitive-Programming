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
int cutpos[55];

int dp[55][55];

int cut(int i, int j) {
  if (i+1 == j) return 0; //for the foor loop below
  
  int& ref = dp[i][j];
  if (ref != -1) return ref;
  
  ref = 2e9;
  
  for (int k = i+1; k < j; ++k) {
    ref = min(ref, cut(i, k) + cut(k, j));
  }
  //return best result PLUS cost of cutting from i to j
  return ref = ref + (cutpos[j]-cutpos[i]);
}


void SOLVE() {
  
  int l;
  while (cin >> l, l != 0) {
    cin >> n;
    for (int i = 1; i <= n; ++i) {
      cin >> cutpos[i];
    }
    cutpos[0] = 0;
    cutpos[n+1] = l;

    memset(dp, -1, sizeof(dp));
    cout << "The minimum cutting is " << cut(0, n+1) << ".\n";
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



















