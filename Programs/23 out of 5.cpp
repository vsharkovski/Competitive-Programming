#include <bits/stdc++.h>
#define endl '\n'
typedef long long ll;
using namespace std;


void main1() {

  int a[5];
  int pi[5] = {0, 1, 2, 3, 4};
  int o1, o2, o3, o4;

  auto f = [](int i, int x, int y) {
    if (i == 0) return x+y;
    if (i == 1) return x-y;
    return x*y;
  };

  while (1) {

    for (int i = 0; i < 5; ++i)
      cin >> a[i];
    if (a[0] == 0 && a[1] == 0 && a[2] == 0 && a[3] == 0 && a[4] == 0)
      break;

    bool found = 0;
    do {
      for (o1 = 0; o1 < 3; ++o1) {
        int b1 = f(o1, a[pi[0]], a[pi[1]]);
        for (o2 = 0; o2 < 3; ++o2) {
          int b2 = f(o2, b1, a[pi[2]]);
          for (o3 = 0; o3 < 3; ++o3) {
            int b3 = f(o3, b2, a[pi[3]]);
            for (o4 = 0; o4 < 3; ++o4) {
              int b4 = f(o4, b3, a[pi[4]]);
              if (b4 == 23) {
                found = 1;
              }
            }
          }
        }
      }
    } while(next_permutation(pi, pi+5));

    if (found) {
      cout << "Possible\n";
    } else {
      cout << "Impossible\n";
    }

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
