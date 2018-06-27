#include <bits/stdc++.h>
#define endl '\n'
typedef long long ll;
using namespace std;

// No backtracking


void main1() {
  //                abcdefg
  int data[10] = {0b1111110, 0b0110000, 0b1101101, 0b1111001, 0b0110011, 0b1011011, 0b1011111, 0b1110000, 0b1111111, 0b1111011};

  int n;
  while (cin >> n, n != 0) {

    int a[n] = {};
    for (int i = 0; i < n; ++i) {
      string s;
      cin >> s;
      int x = 0;
      for (int j = 0; j < 7; ++j) {
        if (s[6-j] == 'Y') {
          x = x | (1 << j);
        }
      }
      a[i] = x;
//      cout << bitset<7>(a[i]) << endl;
    }
    bool found = 0;
    for (int start = 9; start >= n-1; --start) {
      bool ok = 1;
      int broken = 0b0000000;
      for (int i = start, j = 0; j < n && ok; --i, ++j) {
        int x = a[j];
        int og = data[i];
        int diff = og ^ x;
        if (( (og | diff) != og ) || ( broken & x )) {
          ok = 0;
          break;
        }
        broken |= diff;
      }
      if (ok) {
        found = 1;
        break;
      }
    }
    if (found) cout << "MATCH\n"; else cout << "MISMATCH\n";
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
