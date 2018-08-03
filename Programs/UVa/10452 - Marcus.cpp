#include <bits/stdc++.h>
#define endl '\n'
typedef long long ll;
using namespace std;

char a[10][10];

string ok = "@IEHOVA";
bool done = 0;

void explore(int i, int j, string to_say) {
  if (done) return;
  if (a[i][j] == '#') {
    cout << to_say << endl;
    done = 1;
    return;
  }
  if (ok.find(a[i][j]) != string::npos) {
    if (to_say != "") {
      cout << to_say << " ";
    }
    a[i][j] = '.';
    explore(i, j-1, "left");
    explore(i, j+1, "right");
    explore(i-1, j, "forth");
  }
}

void main1() {

  int T;
  cin >> T;
  while (T--) {

    int m, n;
    cin >> m >> n;

    vector<pair<int, int>> v;

    int si, sj;

    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        char ch;
        cin >> ch;
        if (ch == '@') {
          si = i+1;
          sj = j+1;
        }
        a[i+1][j+1] = ch;
      }
    }

    done = 0;
    explore(si, sj, "");

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
