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



//start pos is at pos 0, alt 0
//X is at pos X, alt 0

int X;
int winds[1005][12]; //altitude(0 to 9), pos(0 to 1000 hectamiles)
//pos. wind = save fuel

int dp[1005][12];

int minfuel(int pos, int alt) {
  if (pos == X) return 0;
  
  int& ref = dp[pos][alt]; 
  if (ref != -1) return ref;
  
  if (pos+alt == X) { //force descent
    return ref = 20 - winds[pos][alt] + minfuel(pos+1, alt-1);
  }
  
  ref = 30 + minfuel(pos+1, alt); //stay in place
  if (alt < 9) {
    ref = min(ref, 60 + minfuel(pos+1, alt+1)); //ascend
  }
  if (alt > 0) {
    ref = min(ref, 20 + minfuel(pos+1, alt-1)); //descent
  }
  return ref = ref - winds[pos][alt]; //apply fuel saving at end for efficiency(?)
}



void SOLVE() {
  int T;
  cin >> T;
  
  while (T--) {
    cin >> X;
    X /= 100; //convert miles to hectamiles
    
    for (int alt = 9; alt >= 0; --alt) {
      for (int pos = 0; pos < X; ++pos) {
        cin >> winds[pos][alt];
      }
    }
    
    
    memset(dp, -1, sizeof(dp));
    cout << minfuel(0, 0) << "\n\n";
  
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



















