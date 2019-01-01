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





int N;
vector<int> best[52];
bool dp[52][102];

void Solution() {
  int Case = 1;
  while (cin >> N, N != 0) {
    int totalprofit = 0;
    for (int i = 0; i < N; ++i) {
      int sz, price;
      cin >> sz;
      int sum = 0, maxsum = 0;
      best[i].clear();
      best[i].push_back(0);
      for (int j = 0; j < sz; ++j) {
        cin >> price;
        sum += 10 - price;
        if (sum > maxsum) {
          maxsum = sum;
          best[i].clear();
          best[i].push_back(j + 1);
        } else if (sum == maxsum) {
          best[i].push_back(j + 1);
        }
      }
      totalprofit += maxsum;
    }
    memset(dp, 0, sizeof(dp));
    for (int c : best[0]) {
      dp[1][c] = 1;
    }
    for (int i = 1; i < N; ++i) {
      for (int j = 0; j <= 100; ++j) {
        if (dp[i][j] == 0) continue;
        for (int c : best[i]) {
          dp[i + 1][j + c] = 1;
        }
      }
    }
    if (Case > 1) cout << "\n";
    cout << "Workyards " << Case++ << "\n";
    cout << "Maximum profit is " << totalprofit << ".\n";
    cout << "Number of pruls to buy:";
    for (int j = 0; j <= 100; ++j) {
      if (dp[N][j]) {
        cout << " " << j;
      }
    }
    cout << "\n";
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
