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



void SOLVE() {                                

  int T;
  cin >> T;
  for (int TC = 1; TC <= T; ++TC) {
    
    int n;
    cin >> n;

    vector<int> H(n), W(n);
    for (int i = 0; i < n; ++i) cin >> H[i];
    for (int i = 0; i < n; ++i) cin >> W[i];
    
    vector<int> lis(n), lds(n);
    int lismax = 0, ldsmax = 0;
    
    for (int i = 0; i < n; ++i) {
      int w = W[i];
      lis[i] = w;
      lds[i] = w;
      for (int j = i-1; j >= 0; --j) {
        if (H[j] < H[i]) {
          lis[i] = max(lis[i], w + lis[j]);
        }
        if (H[i] < H[j]) {
          lds[i] = max(lds[i], w + lds[j]);
        }
      }
      
      lismax = max(lismax, lis[i]);
      ldsmax = max(ldsmax, lds[i]);
    }
    
    cout << "Case " << TC << ". ";
    if (lismax >= ldsmax) cout << "Increasing (" << lismax << "). Decreasing (" << ldsmax << ").\n";
    else                  cout << "Decreasing (" << ldsmax << "). Increasing (" << lismax << ").\n";
    
    
    
   
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




                                                 


                                                                                                                                                             


