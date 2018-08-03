#include <bits/stdc++.h>
#define endl '\n'
typedef long long ll;
using namespace std;

int n, m;
vector<string> words;
string rule;
int len;

void f(int i, string progress) {
  if (i == len) {
    cout << progress << endl;
    return;
  }
  if (rule[i] == '0') {
    for (char ch = '0'; ch <= '9'; ++ch) {
      f(i+1, progress+ch);
    }
  } else {
    for (int j = 0; j < n; ++j) {
      f(i+1, progress + words[j]);
    }
  }
}


int main1() {

  while (cin >> n) {

    words.resize(n);
    for (int i = 0; i < n; ++i) {
      cin >> words[i];
    }

    cin >> m;
    cout << "--\n";

    for (int i = 0; i < m; ++i) {
      cin >> rule;
      len = rule.length();
      f(0, "");
    }

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
