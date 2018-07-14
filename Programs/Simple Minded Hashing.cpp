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


int L, S;

//dp
//length <= 26 (strictly increasing)
//prev letter <= 26
// sum <= 26*27/2 = 351
ll dp[30][30][400];

ll ways(int i, int prev, int sum) {
  if (i == L) return sum == S;
  if (sum > S || prev == 26) return 0;
  
  ll& ref = dp[i][prev][sum];
  if (ref != -1) return ref;
  
  ref = 0;
  for (int letter = prev+1; letter <= 26; ++letter) {
    ref += ways(i+1, letter, sum+letter);
  }
  return ref;
}

void SOLVE() {
  
  int CN = 1;
  while (cin >> L >> S, L != 0 && S != 0) {
    
    memset(dp, -1, sizeof(dp));
    cout << "Case " << CN++ << ": " << ways(0, 0, 0) << endl;
    
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



















