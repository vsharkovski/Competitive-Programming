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





string seq;
vector<vi> adjlist;

void examine(int i, int j) {
  char curr = seq[i];

  int k = i+1;
  while (k < j) {
  
    int l = k+1;
    while (seq[l] != seq[k]) ++l;
    
    examine(k, l);
    adjlist[curr].push_back(seq[k]);
    
    k = l+1;
  }
  
}

void SOLVE() {
  int T;
  cin >> T;
  for (int CT = 1; CT <= T; ++CT) {
    adjlist.assign(200, vi());
    cin >> seq;
    
    examine(0, seq.length()-1);
    
    set<int> settie;
    for (char ch : seq) settie.insert(ch);
    
    cout << "Case " << CT << '\n';
    for (char ch : settie) {
      
      cout << ch << " = ";
      
      if (ch == (int)seq[0]) {
        cout << adjlist[ch].size() << '\n';
      } else {
        cout << 1 + adjlist[ch].size() << '\n';
      }
      
    }
    
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














