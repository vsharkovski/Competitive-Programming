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
  for (int CT = 1; CT <= T; ++CT) {

    string N;
    cin >> N;

    int num[3] = {0, 0, 0};

    for (int i = 0; i < N.length(); ++i) {
      ++num[(N[i]-'0') % 3]; // Reduce the digits to mod 3. This makes things easier
    }

    cout << "Case " << CT << ": ";
    // If there is only 1 digit at the start, S wins instantly
    if (num[0] + num[1] + num[2] == 1) {
      cout << "S\n";
      continue;
    }
    // Assuming there is more than 1 digit at the start
    // S's turn. He needs to make sum = 0 (mod 3), otherwise he loses.
    int sum = (num[1] + 2*num[2]) % 3;
    if (num[sum] == 0) { // can't make move
      cout << "T\n";
      continue;
    }
    // make move, now T's turn
    --num[sum];
    sum = 0;
    // Now sum = 0 (mod 3). As per the rules, this must be true for all turns. (after the first obviously)
    // This can only happen if they remove 0's every single time.
    // If num[0] is odd, T wins. Otherwise S wins.
    cout << (num[0] & 1 ? 'T' : 'S') << endl;









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













