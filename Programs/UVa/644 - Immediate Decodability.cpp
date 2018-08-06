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

  int SetNum = 1;

  string code;
  int codeid = 0;
  vector<string> codes;
  map<string, set<int>> m;

  while (cin >> code) {
    if (code != "9") {
      codes.push_back(code);
      string code1 = "";
      for (int i = 0; i < code.length(); ++i) {
        code1 += code[i];
        m[code1].insert(codeid);
      }
      ++codeid;
      continue;
    }

    bool ans = 1;

    for (int i = 0; i < codes.size() && ans; ++i) {
      if (m[codes[i]].size() > 1) {
        ans = 0;
      }
    }

    cout << "Set " << SetNum++ << " is ";
    if (!ans) cout << "not ";
    cout << "immediately decodable\n";
    codes.clear();
    m.clear();
    codeid = 0;
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













