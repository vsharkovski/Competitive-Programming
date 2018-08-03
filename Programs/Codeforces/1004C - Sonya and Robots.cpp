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
	set<int>::iterator it;

	int n;
	cin >> n;

  int a[n+2], ndr[n+2];
  set<int> dr, dl;
  map<int, int> m;
  ll cnt = 0;                         
 
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
    dr.insert(a[i]);
    ++m[a[i]];
  }

  for (int i = 0; i < n; ++i) {
    if (--m[a[i]] == 0) {
    	dr.erase(a[i]);
    }
  	ndr[i] = dr.size();
  }                      
  
  for (int i = 0; i < n; ++i) {
    if (dl.find(a[i]) == dl.end()) {
      cnt += ndr[i];
      dl.insert(a[i]);
   	}
  }                       

  cout << cnt << endl;


                               

}

int main() {
  std::ios::sync_with_stdio(false);                  
  std::cin.tie(nullptr);
  #ifdef _DEBUG
  std::freopen("in.txt", "r", stdin);
  //std::freopen("out.txt", "w", stdout);  
  #endif
  SOLVE();
}




                                                 







