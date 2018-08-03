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
    int c[n], s[n];

    for (int i = 0; i < n; ++i) {
        cin >> s[i];
    }
    for (int i = 0; i < n; ++i) {
        cin >> c[i];
    }

    long long besttc = 4200000000;
    for (int j = 1; j < n-1; ++j) {
        long long bestic = 4200000000, bestjc = c[j], bestkc = 4200000000;
        for (int i = 0; i < j; ++i) {
            if (s[i] < s[j] && bestic > c[i]) {
                bestic = c[i];
            }
        }
        for (int k = j+1; k < n; ++k) {
            if (s[j] < s[k] && bestkc > c[k]) {
                bestkc = c[k];
            }
        }
        besttc = min(besttc, bestic+bestjc+bestkc);
    }
    if (besttc == 4200000000) besttc = -1;
    cout << besttc;
}
