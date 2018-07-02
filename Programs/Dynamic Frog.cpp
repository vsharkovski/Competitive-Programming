#include <iostream>
#include <iomanip>
#include <algorithm>
#include <cmath>
#include <complex>
#include <string>
#include <vector>
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




void SOLVE() {

  char DASH;
  int T, ct = 1;
  cin >> T;
  while (T--) {

    int n, d;
    cin >> n >> d;

    vector<pair<int, char>> stones;
    stones.push_back({0, 'B'});
    for (int i = 0; i < n; ++i) {
      pair<int, char> p;
      cin >> p.second >> DASH >> p.first;
      stones.push_back(p);
    }
    stones.push_back({d, 'B'});

    int maxi = 0, pos = stones[0].first;
    bool zname = 1;

    for (int i = 1; i <= n+1; ++i) {
      if (stones[i].second == 'B') {
        maxi = max(maxi, stones[i].first-pos);
        pos = stones[i].first;
      } else if (stones[i].second == 'S') {
        if (zname) {
          zname = 0;
          maxi = max(maxi, stones[i].first-pos);
          pos = stones[i].first;
          stones[i].second = 'x';
        } else {
          zname = 1;
        }
      }
    }

    for (int i = n+1; i >= 0; --i) {
      if (stones[i].second == 'B') {
        maxi = max(maxi, pos-stones[i].first);
        pos = stones[i].first;
      } else if (stones[i].second == 'S') {
        maxi = max(maxi, pos-stones[i].first);
        pos = stones[i].first;
        stones[i].second = 'x';
      }
    }

    cout << "Case " << ct << ": " << maxi << endl;

    ct++;
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
