
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

  int n;
  cin >> n;

  string a, b;
  cin >> a >> b;

  ll br0zv = 0, br1zv = 0, br0 = 0, br1 = 0;
  for (int i = 0; i < n; ++i) {
    if (a[i] == '0') ++br0;
    else ++br1;
    if (b[i] == '0') {
      if (a[i] == '0') ++br0zv;
      else ++br1zv;
    }
  }

//  cout << br0 << " " << br0zv << " " << br1 << " " << br1zv << endl;

  ll cnt = br0zv*(br1 - br1zv) + br1zv*br0;

  cout << cnt << endl;










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





