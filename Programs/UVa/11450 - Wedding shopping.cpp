#include <iostream>
#include <iomanip>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <complex>
#include <utility>
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
typedef std::pair<int, int> pii;

// Credit to the book 'Competitive Programming 3'


int m, c;
int price[25][25]; //g, model
int memo[210][25]; //money left, g

int shop(int money, int g) {
  if (money < 0) return -1e9;
  if (g == c) {
    return m - money; //return total money spent from all shopping
  }
  if (memo[money][g] != -1) {
    return memo[money][g]; //TOP DOWN MEMOIZATION
  }
  int ans = -1;
  for (int model = 1; model <= price[g][0]; ++model) {
    ans = max(ans, shop(money - price[g][model], g+1));
  }
  memo[money][g] = ans;
  return ans;
}

void SOLVE() {

  int T;
  cin >> T;
  while (T--) {

    cin >> m >> c;
    memset(memo, -1, sizeof(memo));

    for (int i = 0; i < c; ++i) {
      int k;
      cin >> k;
      price[i][0] = k;
      for (int j = 1; j <= k; ++j) {
        cin >> price[i][j];
      }
    }

    int score = shop(m, 0);
    if (score < 0) cout << "no solution\n";
    else cout << score << endl;


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
















