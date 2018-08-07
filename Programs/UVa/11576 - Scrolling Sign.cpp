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






void MAIN() {
  int T;
  cin >> T;
  while (T--) {

    int k, w;
    cin >> k >> w;

    string words[102];

    for (int i = 0; i < w; ++i) {
      cin >> words[i];
    }

    int cnt = k; //words[0]
    for (int i = 1; i < w; ++i) {
      cnt += k;
      for (int p0 = 0; p0 < k; ++p0) {
        if (words[i-1][p0] == words[i][0]) {
          int p = p0, j = 0;
          while (p < k && words[i-1][p] == words[i][j]) {
            ++p, ++j;
          }
          if (p == k) {
            cnt -= j;
            break;
          }
        }
      }
    }

    cout << cnt << endl;


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













