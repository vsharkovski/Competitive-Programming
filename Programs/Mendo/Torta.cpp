#include <bits/stdc++.h>
using namespace std;
 
int main() {
    int n, k; cin >> n >> k;
    int cp = 1001, cs = 1001;
    for (int i = 0; i < k; ++i) {
        int p, s; cin >> p >> s;
        if (p < cp) cp = p;
        if (s < cs) cs = s;
    }
    //cout << "cs = " << cs << "; cp = " << cp << endl;
    //cout << "cs*n = " << cs*n << "; cp*(n/6+1) = " << cp*(n/6+1) << "; cp*(n/6) + cs*(n%6) = " << cp*(n/6) + cs*(n%6) << endl;
    int js = min({cs*n, cp*(n/6+1), cp*(n/6) + cs*(n%6)});
    cout << js << endl;
}
