#include <bits/stdc++.h>
#define endl '\n'
typedef long long ll;
using namespace std;

int n, k, closest = 0, indexes;
vector<int> v;

void f(int i, int x, int progress) {
  bool succeededInLife = 0;
  for (int j = i+1; j < k; ++j) {
    if (v[j] + x <= n) {
      f(j, v[j]+x, progress | (1<<j));
      succeededInLife = 1;
    }
  }
  if (!succeededInLife && closest < x && x <= n) {
    closest = x;
    indexes = progress;
  }
}

int main1() {

  while (cin >> n) {

    closest = 0;

    cin >> k;
    v.resize(k);
    for (int i = 0; i < k; ++i) {
      cin >> v[i];
    }

    for (int i = 0; i < k; ++i) {
      f(i, v[i], (1<<i));
    }

    for (int i = 0; i < k; ++i) {
      if (indexes & (1 << i)) {
        cout << v[i] << ' ';
      }
    }

    cout << "sum:" << closest << endl;

  }

  return 0;
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
