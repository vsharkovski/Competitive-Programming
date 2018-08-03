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





int VISITED = 2;

int N;
int grid[30][30];

void dfs(int i, int j) {
  if (i < 0 || i >= N || j < 0 || j >= N || grid[i][j] != 1) return;
  grid[i][j] = VISITED;
  dfs(i+1, j);
  dfs(i-1, j);
  dfs(i, j+1);
  dfs(i, j-1);
  dfs(i+1, j+1);
  dfs(i+1, j-1);
  dfs(i-1, j+1);
  dfs(i-1, j-1);
}

void SOLVE() {

  int TC = 0;
  while (cin >> N) {
  
    for (int i = 0; i < N; ++i) {
      for (int j = 0; j < N; ++j) {
        char ch;
        cin >> ch;
        grid[i][j] = ch - '0';
      }
    }
    
    int numCC = 0;
    
    for (int i = 0; i < N; ++i) {
      for (int j = 0; j < N; ++j) {
        if (grid[i][j] == 1) {
          ++numCC;
          dfs(i, j);
        }
      }
    }
    
    cout << "Image number " << ++TC << " contains " << numCC << " war eagles.\n";
  
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














