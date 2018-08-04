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



// thank you SOTF.

void MAIN() {

  int T;
  cin >> T;
  while (T--) {

    int N, M; //br instr., br. studenti
    cin >> N >> M;

    int pr[33] = {};

    for (int i = 0; i < M; ++i) {
      for (int j = 0; j < N; ++j) {
        int priority;
        cin >> priority;
        if (priority == 1) {
          ++pr[j];
        }
      }
    }

    ll ans = 1;
    for (int i = 0; i < N; ++i) {
      ans *= max(1, pr[i]);
    }

    cout << ans << endl;


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













