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


// Complete search method, viable because n <= 20


int n, totalw, halfw;
int a[22];
bool found = 0;

void f(int i, int w, int prog) {
  if (found || w > halfw) return;
  if (w == halfw) {
    found = 1;
    return;
  }
  if (i < n) {
    f(i+1, w, prog);
    f(i+1, w + a[i], prog | i);
  }
}

void SOLVE() {

  string line;
  int T;
  cin >> T;
  getline(cin, line); //UVA has terrible input
  
  while (T--) {
    n = 0;
    totalw = 0;
    found = 0;
    
    getline(cin, line);
    stringstream ss(line);

    while (ss >> a[n]) {
      totalw += a[n];
      ++n;
    }
    halfw = totalw/2;

    if (totalw % 2 == 1) {
      cout << "NO\n";
      continue;
    }
    
    f(0, 0, 0);
    if (found) cout << "YES\n"; else cout << "NO\n";
    
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



















