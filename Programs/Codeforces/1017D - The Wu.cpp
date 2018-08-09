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







int n, m, q;

int str2int(string &str) {
  int x = 0;
  for (int y = n-1; y >= 0; --y) {
    if (str[y] == '1') x |= (1 << y);
  }
  return x;
}

int S[4100]; //S[i] = num. of i in S
int w[12];

int wudiff[4100]; //total w of a^b
int wucnt[4100][1300]; //allwu[mask][wu] = cnt. of wu possible from mask in regards to S
int ans[4100][102]; //ans[mask][k] = uslovot

void MAIN() {

  cin >> n >> m >> q;
  for (int i = 0; i < n; ++i) {
    cin >> w[i];
  }

  memset(S, 0, sizeof(S));
  for (int i = 0; i < m; ++i) {
    string s;
    cin >> s;
    ++S[str2int(s)];
  }

  for (int mask = 0; mask < (1 << n); ++mask) {
    int cwu = 0;
    for (int j = 0; j < n; ++j) {
      if (mask & (1 << j)) cwu += w[j];
    }
    wudiff[mask] = cwu;
  }

  memset(wucnt, 0, sizeof(wucnt));
  for (int mask1 = 0; mask1 < (1 << n); ++mask1) {
    for (int mask2 = 0; mask2 < (1 << n); ++mask2) {
      wucnt[mask1][wudiff[ (~(mask1^mask2)) ^ (~((1<<n)-1)) ]] += S[mask2];
//      cout << bitset<12>(mask1) << "^" << bitset<12>(mask2) << "=" << bitset<12>((~(mask1^mask2)) ^ (~((1<<n)-1))) << endl;
    }
  }

  for (int mask = 0; mask < (1 << n); ++mask) {
    for (int k = 0; k <= 100; ++k) {
      for (int l = 0; l <= k; ++l) {
        ans[mask][k] += wucnt[mask][l];
      }
    }
  }

  while (q--) {
    string t;
    int k;
    cin >> t >> k;
    cout << ans[str2int(t)][k] << endl;
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






