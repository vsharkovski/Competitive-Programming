#include <iostream>
#include <iomanip>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <complex>
#include <functional>
#include <utility>
#include <string>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <list>
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





int dr[] = {1, 0, -1, 0, 1, -1, -1, 1};
int dc[] = {0, 1, 0, -1, 1, 1, -1, -1};

void MAIN() {

  int L;
  char grid[100][100];

  cin >> L;
  for (int i = 0; i < L; ++i) {
    for (int j = 0; j < L; ++j) {
      cin >> grid[i][j];
    }
  }

  string word;
  while (cin >> word, word != "0") {
    int len = word.length();
    bool found = 0;
    for (int r = 0; r < L && !found; ++r) {
      for (int c = 0; c < L && !found; ++c) {
        if (grid[r][c] != word[0]) continue;
        for (int d = 0; d < 8 && !found; ++d) {
          int rk  = r + (len-1)*dr[d], ck = c + (len-1)*dc[d];
          if (rk >= 0 && rk < L && ck >= 0 && ck < L) {
            bool OK = 1;
            int r1 = r, c1 = c;
            for (int m = 1; m < len && OK; ++m) {
              r1 += dr[d];
              c1 += dc[d];
              if (grid[r1][c1] != word[m]) {
                OK = 0;
              }
            }
            if (OK) {
              found = 1;
              cout << r+1 << "," << c+1 << " " << rk+1 << "," << ck+1 << endl;
            }
          }
        }

      }
    }
    if (!found) {
      cout << "Not found\n";
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
  MAIN();
}













