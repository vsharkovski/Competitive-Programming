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







void SOLVE() {

  int n;
  cin >> n;
  int s1 = 0, s2 = 0;
  for (int i = 0; i < n; ++i) {
    int x;
    cin >> x;
    s1 += x;
  }
  for (int i = 0; i < n; ++i) {
    int y;
    cin >> y;
    s2 += y;
  }
  if (s2 <= s1) cout << "Yes"; else cout << "No";



}

