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


/* 
Gets WA. However, output is correct on Batman's (the only) input on uDebug.
HOWEVER, my output abruptly stops at line 97 (for that input) for some reason,
and I cannot figure out why because of how bad the input format on UVa tends to be.
If you can find a flaw in the program, feel free to prove that it's wrong!
*/



int t1, t2, n; // T1 + T2 <= 300; n <= 30
int numsamples[32]; // at site i, Mi samples
int costs[32][22][2]; // costs[site.num][amount.items][NCPC or BCEW]

int dp[32][302][302]; //i, rem1, rem2
int pf[32][302][302]; //path to output

int f(int idx, int rem1, int rem2) {
  if (idx == n) return 0;
  
  int& ref = dp[idx][rem1][rem2];
  if (ref != -1) return ref;
  
  int& path = pf[idx][rem1][rem2];
  ref = 2e9;
  
  for (int amnt1 = 0, amnt2 = numsamples[idx]; amnt1 <= numsamples[idx]; ++amnt1, --amnt2) {
    if (amnt1 <= rem1 && amnt2 <= rem2) {
      int ref1 = costs[idx][amnt1][0] + costs[idx][amnt2][1] + f(idx+1, rem1 - amnt1, rem2 - amnt2);
      if (ref1 <= ref) {
        ref = ref1;
        path = amnt1; // pf[i][t1][t2]
      }
    }
  }
  
  return ref;
}


void SOLVE() {

  while (cin >> t1 >> t2, t1 != 0 && t2 != 0) {  
    cin >> n;
    
    for (int i = 0; i < n; ++i) {
      cin >> numsamples[i];
      for (int k = 0; k < 2; ++k) {
        costs[i][0][0] = costs[i][0][1] = 0;
        for (int j = 1; j <= numsamples[i]; ++j) {
          cin >> costs[i][j][k];        
        }
      }
    }
    memset(dp, -1, sizeof(dp));
    
    int ans = f(0, t1, t2);
    cout << ans << '\n';
    
    for (int i = 0; i < n; ++i) {
      int amnt1 = pf[i][t1][t2];
      cout << amnt1;
      if (i < n-1) cout << ' ';

      t1 -= amnt1;
      t2 -= (numsamples[i] - amnt1);
    }
    
    cout << "\n\n";
  
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



















