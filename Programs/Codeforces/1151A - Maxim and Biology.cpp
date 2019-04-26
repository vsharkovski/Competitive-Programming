#include <bits/stdc++.h>
using namespace std;
typedef long long ll;



string want = "ACTG";

int mindist(char have, char want) {
    int res1 = 0, res2 = 0;
    char have1 = have;
    while (have1 != want) {
        if (have1 == 'Z') have1 = 'A';
        else have1 += 1;
        ++res1;
    }
    while (have != want) {
        if (have == 'A') have = 'Z';
        else have -= 1;
        ++res2;
    }
    return min(res1, res2);
}

int getans(string& s, int pos) {
    int res = 0;
    for (int i = 0; i < 4; ++i) {
        res += mindist(s[i+pos], want[i]);
    }
    return res;
}

int main() {
    int n;
    string s;
    cin >> n >> s;
    int ans = 10000;
    for (int i = 0; i+4 <= n; ++i) {
        ans = min(ans, getans(s, i));
    }
    cout << ans;
}
