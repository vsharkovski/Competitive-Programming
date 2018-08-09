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



struct St {
  int id, sum;
  bool operator < (St &rhs) {
    if (sum == rhs.sum) return id < rhs.id;
    return sum > rhs.sum;
  }
};

void MAIN() {

  int n;
  cin >> n;

  vector<St> v;
  for (int i = 1; i <= n; ++i) {
    St s;
    s.id = i;
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    s.sum = a+b+c+d;
    v.push_back(s);
  }

  sort(all(v));

  for (int i = 0; i < n; ++i) {
    if (v[i].id == 1) {
      cout << i+1 << endl;
      return;
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







