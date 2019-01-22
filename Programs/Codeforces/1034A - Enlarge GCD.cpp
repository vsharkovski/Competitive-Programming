#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
typedef pair<int, int> pi;
typedef vector<int> vi;
template<class Key, class Compare = less<Key>>
using Tree = tree<Key, null_type, Compare, rb_tree_tag, tree_order_statistics_node_update>;




const int MAX = 15000000;
bitset<5000> iscomposite;
vector<int> primes;

void getprimes() {
  for (ll p = 2; p*p <= MAX; ++p) {
    if (iscomposite[p]) continue;
    primes.push_back(p);
    for (ll x = p*p; x*x <= MAX; x += p) {
      iscomposite[x] = 1;
    }
  }
}

int n;
vector<int> a;
map<int, int> cnt;

void getdata(int x) {
  for (int p : primes) {
    if (p*p > x) break;
    if (x % p == 0) {
      ++cnt[p];
      while (x % p == 0) {
        x /= p;
      }
    }
  }
  if (x > 1) {
    ++cnt[x];
  }
}

void Main() {
  getprimes();
  cin >> n;
  a.resize(n);
  int g;
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
    if (i == 0) {
      g = a[i];
    } else {
      g = __gcd(g, a[i]);
    }
  }
  for (int i = 0; i < n; ++i) {
    a[i] /= g;
    getdata(a[i]);
  }
  int ans = -1;
  for (auto& kvp : cnt) {
    int toremove = n - kvp.second;
    if (ans == -1 || ans > toremove) {
      ans = toremove;
    }
  }
  cout << ans << '\n';
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  #ifdef _DEBUG
//  freopen("in.txt", "r", stdin);
//  freopen("out.txt", "w", stdout);
  #endif
  Main();
  return 0;
}
