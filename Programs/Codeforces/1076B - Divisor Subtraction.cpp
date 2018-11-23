#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define all(v) begin(v), end(v)
typedef long long ll;
typedef long double ld;
typedef std::pair<int, int> ii;
typedef std::vector<ii> vii;
typedef std::vector<int> vi;







void Solve() {

    ll n;
    cin >> n;

    for (ll p = 2; p*p <= n; ++p) {
        if (n % p == 0) {
            n -= p;
            cout << 1 + (n / 2) << endl;
            return;
        }
    }

    cout << 1 << endl;

}



int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  #ifdef _DEBUG
  std::freopen("in.txt", "r", stdin);
  std::freopen("out.txt", "w", stdout);
  #endif
  Solve();
}
