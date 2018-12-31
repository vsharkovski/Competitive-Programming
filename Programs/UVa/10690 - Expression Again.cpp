#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
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
template <class Key, class Compare = less<Key>> // find_by_order, order_of_key (for multiset: pair(val, time of insertion))
using Tree = tree<Key, null_type, Compare, rb_tree_tag, tree_order_statistics_node_update>;




const int OFS = 2502;
const int inf = 1e9;

int N, M;
int sum;
int numbers[101];
int dp[5005][51][101];
bool mode;

int F(int sa, int na, int i) {
  int& res = dp[OFS+sa][na][i];
  if (res != -1) return res;
  if (na == N) {
    return res = sa * (sum - sa);
  }
  if (i == N+M) {
    return res = mode == 0 ? -inf : inf;
  }
  int res1 = F(sa, na, i + 1);
  int res2 = F(sa + numbers[i], na + 1, i + 1);
  return res = mode == 0 ? max(res1, res2) : min(res1, res2);
}

void Solution() {
  while (cin >> N >> M) {
    sum = 0;
    for (int i = 0; i < N+M; ++i) {
      cin >> numbers[i];
      sum += numbers[i];
    }
    memset(dp, -1, sizeof(dp));
    mode = 0;
    int maxi = F(0, 0, 0);
    memset(dp, -1, sizeof(dp));
    mode = 1;
    int mini = F(0, 0, 0);
    cout << maxi << ' ' << mini << '\n';
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  #ifdef _DEBUG
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
  #endif
  Solution();
}
