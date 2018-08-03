#include <bits/stdc++.h>
using namespace std;



int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
//#ifdef _DEBUG
//	freopen("input.txt", "r", stdin);
////	freopen("output.txt", "w", stdout);
//#endif

    int n;
    cin >> n;
    string s;
    cin >> s;
    map<string, int> m;
    int maxc = 0;
    string maxz = "";
    for (int i = 1; i < n; ++i) {
        string z = s.substr(i-1, 2);
        m[z]++;
        if (m[z] > maxc) {
            maxz = z;
            maxc = m[z];
        }
    }
    cout << maxz;
}
