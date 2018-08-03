#include <bits/stdc++.h>
#define endl '\n'
typedef long long ll;
using namespace std;



void main1() {

  int n;
  vector<int> v;
  int total = 0;

  cin >> n;
  double nd = n;

  for (int i = 0; i < n; ++i) {
    int x;
    cin >> x;
    v.push_back(x);
    total += x;
  }

  sort(v.begin(), v.end());

  int i = 0;
  double avg = double(total)/nd;
  while (avg < 4.5) {
    total = total - v[i] + 5;
    i++;
    avg = double(total)/nd;
  }

  cout << i << endl;
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
