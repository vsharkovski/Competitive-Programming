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

#define endl '\n'
#define EPS 1e-9

using namespace std;
typedef long long ll;
typedef std::pair<int, int> pii;


int n, d, m;
ll OGnumbers[205];
ll numbers[205]; //for the trick with the longer line below to work ([... + d] % d)

ll dp[205][12][22]; //i, num.taken, sum (mod d) ; d <= 20

ll take(int id, int num_taken, int sum) {
  if (num_taken == m) return sum%d == 0; // it's improtant this is before the next line
  if (id == n) return 0;
  
  ll& ref = dp[id][num_taken][sum];
  if (ref != -1) return ref;
  return ref = 0 + take(id+1, num_taken, sum) + take(id+1, num_taken+1, (sum + numbers[id] + d) % d);
}


/*
optimization idea: take all numbers, reduce mod d, calculate what can be added from each position 'i' in O(N^2)
but then solution would be in O(N^2 * Q), which is slower than this solution, O(N*M*D)
*/

void SOLVE() {
  int q;
 
  int SN = 1;
  while (cin >> n >> q, n != 0 && q != 0) {
    for (int i = 0; i < n; ++i) {
      cin >> OGnumbers[i];
    }
    cout << "SET " << SN << ":\n";
    
    for (int i = 1; i <= q; ++i) {
      cin >> d >> m;
      memset(dp, -1, sizeof(dp));
      
      for (int j = 0; j < n; ++j) {
        numbers[j] = OGnumbers[j] % d;
      }
      
      ll cnt = take(0, 0, 0);
      cout << "QUERY " << i << ": " << cnt << endl;
    }
    
    ++SN;
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



















