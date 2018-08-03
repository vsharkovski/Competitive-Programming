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

	int n, d;
	cin >> n >> d;

	int a[n];
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}

	int cnt = 2;
	map<int, bool> m;

	for (int i = 0; i < n; ++i) {
	 // cout << "(i=" << i << ")";
		if (i > 0 && a[i]-d >= a[i-1]+d &&  !m[a[i]-d]) {
			m[a[i]-d] = 1;
			++cnt;
		//	cout << a[i]-d << "(b) ";
		}
		if (i < n-1 && a[i]+d <= a[i+1]-d && !m[a[i]+d]) {
			m[a[i]+d] = 1;
		  ++cnt;
		 // cout << a[i]+d << "(a) ";
		}
	
	}   //cout << endl;
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




                                                 





