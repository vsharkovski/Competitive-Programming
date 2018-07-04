#include <iostream>
#include <iomanip>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <complex>
#include <utility>
#include <string>
#include <vector>
#include <queue>
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


void SOLVE() {

  int n, k;
  cin >> n >> k;

  double a[n];
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }

  double maxi = -1;
  for (k = k; k <= n; ++k) {
    queue<double> nums;
    double sum = 0;
    for (int i = 0; i < n; ++i) {
      if (i < k) {
        nums.push(a[i]);
        sum += a[i];
        if (nums.size() == k) {
          maxi = max(maxi, sum/k);
        }
      } else {
        sum -= nums.front();
        nums.pop();
        nums.push(a[i]);
        sum += a[i];
        maxi = max(maxi, sum/k);
      }
    }
  }

  cout << setprecision(15) << maxi << endl;

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














