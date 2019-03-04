#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pi;
typedef vector<int> vi;



void Main() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    bool hadc = false;
    int res = 0, a = 0, b = 0;
    for (int i = 0; i < n; ++i) {
        if (s[i] == 'C') {
            if (hadc) {
                if (a <= b) {
                    ++res;
                }
            } else {
                hadc = true;
            }
            a = b = 0;
        } else if (s[i] == 'A') {
            ++a;
        } else if (s[i] == 'B') {
            ++b;
        }
    }
    if (res > 0) {
        cout << res << '\n';
    } else {
        cout << "POGODENA\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    Main();
}
