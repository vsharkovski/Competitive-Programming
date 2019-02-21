#include <algorithm>
#include <utility>
#include <cmath>
#include <cstring>
#include <bitset>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <queue>
#include <deque>
#include <list>
#include <stack>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pi;
typedef pair<ll, ll> pl;
typedef pair<ld, ld> pd;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<ld> vd;
typedef vector<pi> vpi;
typedef vector<pl> vpl;


class BeautifulString
{
  public:
    int remove(string str)
    {
  vector<int> data[200];
  int n = str.length();
  for (int i = 0; i < n; ++i) {
    data[str[i]].push_back(i);
  }
  int ans = 1e9;
  for (char ch = 'a'; ch <= 'z'; ++ch) {
    for (int idx = 1; idx < data[ch].size(); ++idx) {
      ans = min(ans, data[ch][idx] - data[ch][idx-1] - 1);
    }
  }
  if (ans == 1e9) ans = -1;
  return ans;
    }
};
//
//#ifdef _DEBUG
////#include <iostream>
//int main() {
//
//}
//#endif
