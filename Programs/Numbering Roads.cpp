#include <iostream>
#include <cmath>
using namespace std;

int main() {
  int CN = 1;
  int N, R;
  while (cin >> R >> N, R != 0 && N != 0) {
    cout << "Case " << CN++ << ": ";
    int ans = ceil(double(R)/double(N) - 1.0);
    if (ans > 26) cout << "impossible\n";
    else cout << ans << '\n';
  }
}
