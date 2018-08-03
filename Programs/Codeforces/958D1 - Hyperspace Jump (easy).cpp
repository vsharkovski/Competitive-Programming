#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


int main() {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif

    int m;
    cin >> m;
    double vals[m];
    map<double, int> valcnt;
    for (int i = 0; i < m; ++i) {
        string s;
        cin >> s;
        int n1 = 0, n2 = 0, n3 = 0;
        bool sawplus = 0, sawclp = 0;
        for (int j = 1; j < s.length(); ++j) {
            if (s[j] == '+') {
                sawplus = 1;
                j += 1;
            } else if (s[j] == ')') {
                sawclp = 1;
                j += 2;
            }
            if (!sawplus) {
                n1 = n1*10 + (s[j]-'0');
            } else if (!sawclp) {
                n2 = n2*10 + (s[j]-'0');
            } else {
                n3 = n3*10 + (s[j]-'0');
            }
        }
//        cout << n1 << " " << n2 << " " << n3 << '\n';
        double val = round(1000000000.0*( ((double)n1+(double)n2) / ((double)n3) ))/1000000000.0;
        ++valcnt[val];
//        cout << "{" << valcnt[val] << "}\n";
        vals[i] = val;
    }
    for (double val : vals) {
        cout << valcnt[val] << " ";
    }

}
