#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;



int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    int n;
    cin >> n;
    string t;
    cin >> t;
    vector<int> divs;
    for (int i = 1; i <= n; ++i) {
        if (n%i == 0) {
            divs.push_back(i);
        }
    }
    for (int len : divs) {
        reverse(t.begin(), t.begin()+len);
    }
    cout << t;

}
