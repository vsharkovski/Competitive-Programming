#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

inline bool ispal(string s) {
    for (int i = 0, j = s.length()-1; i <= j; ++i, --j) {
//        cout << "s[" << i << "]=" << s[i] << "   s[" << j << "]=" << s[j] << endl;
        if (s[i] != s[j]) return false;
    }
    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif

    string s;
    cin >> s;
    while (ispal(s)) {
//        cout << s << " is pal\n";
        if (s.length() == 1) {
            s = "";
            break;
        }
        s = s.substr(0,s.length()-1);
    }
    cout << s.length();
}
