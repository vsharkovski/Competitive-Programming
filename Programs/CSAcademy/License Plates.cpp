#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pi;
typedef vector<int> vi;




string p;

int bf(int i, char previ) {
    if (i == p.length()) {
        return 1;
    } else {
        int res = 0;
        if (p[i] == 'd') {
            for (char ch = '0'; ch <= '9'; ++ch) {
                if (ch != previ) {
                    res += bf(i+1, ch);
                }
            }
        } else {
            for (char ch = 'a'; ch <= 'z'; ++ch) {
                if (ch != previ) {
                    res += bf(i+1, ch);
                }
            }
        }
        return res;
    }
}

void Main() {
    cin >> p;
    int ans = bf(0, '_');
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    #ifndef _DEBUG
    #endif
    Main();
    return 0;
}
