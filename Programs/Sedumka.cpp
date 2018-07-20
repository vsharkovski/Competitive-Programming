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
#define all(v) begin(v), end(v)

using namespace std;
typedef long long ll;
typedef std::pair<int, int> ii;
typedef std::vector<ii> vii;
typedef std::vector<int> vi;
const int UNVISITED = -1, VISITED = 0;



inline ll pow10(int p) {
  ll x = 1;
  for (int i = 0; i < p; ++i) {
    x *= 10;
  }
  return x;
}

void SOLVE() {

  ll _n;
  int k;
  cin >> _n >> k;
  
  string n = to_string(_n+1);
  
  int br7 = 0;
  for (int i = 0; i < n.length(); ++i) {
    if (n[i] == '7') {
      ++br7;
    }
  }
  
  reverse(all(n));
  
  int i = 0;
  
  while (br7 < k) {
    if (i == n.length()) {
      n += '7';
      ++br7;
    } else {
      if (n[i] < '7') {
        
        n[i] = '7';
        ++br7;
        
        for (int j = 0; j < i; ++j) {
          if (n[j] != '7') {
            if (br7 < k) {
              n[j] = '7';
              ++br7;
            } else {
              n[j] = '0';
            }
          }
        }
        
      } else if (n[i] > '7') {
        
        reverse(all(n));
        n = to_string( stoll(n) + pow10(i) );
        reverse(all(n));
        
        
        br7 = 0;
        for (char ch : n)
          if (ch == '7')
            ++br7;
      
        i = -1;
        
        
      }
    }
    ++i;
  }

  reverse(all(n));
  
  cout << n << endl;






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
