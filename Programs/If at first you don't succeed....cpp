#include <bits/stdc++.h>
#define endl '\n'
typedef long long ll;
using namespace std;



void main1() {

  int a, b, c, n;
  cin >> a >> b >> c >> n;

  int x = n+c-a-b;
  if (x <= 0 || a+b<c || c > n || a > n || b > n || x > n || c > a || c > b) {
    cout << -1;
  } else {
    cout << x;
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
