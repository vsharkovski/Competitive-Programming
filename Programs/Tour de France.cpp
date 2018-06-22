#include <bits/stdc++.h>
#define endl '\n'
typedef long long ll;
using namespace std;




void _initialize();
int main() {
  _initialize();

  cout << setprecision(2) << fixed;

  int numSpFr, numSpRe; // num <= 10
  while (cin >> numSpFr, numSpFr != 0) {
    cin >> numSpRe;

    vector<int> gearsFr(numSpFr), gearsRe(numSpRe);
    for (int i = 0; i < numSpFr; ++i) {
      cin >> gearsFr[i]; // 10 <= teeth <= 100
    }
    for (int i = 0; i < numSpRe; ++i) {
      cin >> gearsRe[i];
    }

    vector<double> ratios;

    for (int i = 0; i < numSpRe; ++i) {
      for (int j = 0; j < numSpFr; ++j) {
        double n = gearsRe[i], m = gearsFr[j];
        double rat = n/m;
        ratios.push_back(rat);
      }
    }
    sort(ratios.begin(), ratios.end());

    double maxspr = -1;
    for (int i = 1; i < ratios.size(); ++i){
      maxspr = max(maxspr, ratios[i]/ratios[i-1]);
    }

    cout << maxspr << endl;
  }






}




void _initialize() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  #ifdef _DEBUG
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
  #endif
}
