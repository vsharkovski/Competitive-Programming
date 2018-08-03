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


int m, m2, n;
int price[102], favor[102];

int dp[102][10500]; //MAXFAVOUR dp[id][money]

int sacc(int id, int spent) {
  if (id == n) {
    if (spent > m && (spent <= 2000 || spent > m2)) return -2e9;
    else return 0;
  }
  
  int& ref = dp[id][spent];
  if (ref != -1) return ref;
  
  ref = sacc(id+1, spent);
  
  int spent1 = spent + price[id];
  if (spent1 <= m2) {
    ref = max(ref, favor[id] + sacc(id+1, spent1));
  }
  
  return ref;
}

void SOLVE() {
  
  while (cin >> m >> n) {
    memset(dp, -1, sizeof(dp));
    
    for (int i = 0; i < n; ++i) {
      cin >> price[i] >> favor[i];
    }
 
    m2 = m+200;
    
    cout << sacc(0, 0) << endl;
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



















