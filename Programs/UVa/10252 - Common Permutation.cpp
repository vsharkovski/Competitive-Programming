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

  string s1, s2;
  while (getline(cin, s1), getline(cin, s2)) {

    int a1[200] = {}, a2[200] = {};
    for (char ch : s1) ++a1[(int)ch];
    for (char ch : s2) ++a2[(int)ch];
    for (char ch = 'a'; ch <= 'z'; ++ch) {
      for (int i = 0; i < min(a1[(int)ch], a2[(int)ch]); ++i) {
        cout << ch;
      }
    }
    cout << endl;

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













