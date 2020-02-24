#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
 
 
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> t(n);
    int sum = 0;
    for (int i = 0; i < n; ++i) {
        cin >> t[i];
        sum += t[i];
    }
    double ans = double(sum)/double(n);
    int ansi = 0;
    for (int i = 0; i < n; ++i) {
        sum -= t[i];
        double res = double(sum)/double(n-i-1);
        if (res > ans) {
            ans = res;
            ansi = i+1;
        }
    }
    cout << ansi << '\n';
}
