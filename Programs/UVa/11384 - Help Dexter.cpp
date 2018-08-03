#include <bits/stdc++.h>
#define endl '\n'
typedef long long ll;
using namespace std;


void main1() {

  int T;
  cin >> T;
  for (int Y = 1; Y <= T; ++Y) {

    int p, q;
    cin >> p >> q;

    int div = (1<<q);
    ll r1 = -1, r2 = -1;

    for (int mask = (1<<p); mask < (1<<(p+1)); ++mask) {
        ll num = 0;
        for (int j = 0; j < p; ++j) {
          if (mask & (1 << j)) {
            num = num*10 + 2;
          } else {
            num = num*10 + 1;
          }
        }
        if (num % div == 0) {
          if (r1 == -1) r1 = num;
          else r2 = num;
        }
    }

    cout << "Case " << Y << ": ";
    if (r1 == -1 && r2 == -1) {
      cout << "impossible";
    } else if (r1 != -1 && r2 == -1) {
      cout << r1;
    } else if (r1 == -1 && r2 != -1) {
      cout << r2;
    } else {
      cout << r1 << ' ' << r2;
    }
    cout << endl;

  }


}






int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);
  #ifdef _DEBUG
  std::freopen("in.txt", "r", stdin);
  std::freopen("out.txt", "w", stdout);
  #endif
  main1();
}
