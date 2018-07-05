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


// the cost of cut is determined by the length of the stick being cut
// minimize the cost

int L, N;
int A[55];

int dp[55][55];

int cut(int left, int right) {
  if (left+1 == right) return 0; //no need to cut
  if (dp[left][right] != -1) return dp[left][right];

  //try all possible cutting points and pick best
  int mini = 2e9;
  for (int i = left+1; i <= right-1; ++i) {
    // mini = min( cost + cut(L, i) + cut(i, R) )
    mini = min(mini, cut(left, i) + cut(i, right));
  }
  return dp[left][right] = (A[right] - A[left]) + mini;
}



void SOLVE() {

  while (cin >> L >> N, L != 0) {
    memset(dp, -1, sizeof(dp));

    A[0] = 0;
    for (int i = 1; i <= N; ++i) {
      cin >> A[i];
    }
    A[N+1] = L;

    cout << "The minimum cutting is " << cut(0, N+1) << ".\n";
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












