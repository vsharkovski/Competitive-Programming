#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;



int main() {
    int n;
    cin >> n;
    vector<int> v1, v2;
    vector<bool> b(26, false);
    for (int i = 0; i < n; ++i) {
        string s;
        cin >> s;
        int j = s[0] - 'a';
        if (b[j]) {
            v1.push_back(j);
        } else {
            v2.push_back(j);
        }
        b[j] = !b[j];
    }
    int ans = 0;
    for (int i = 0; i < v1.size(); ++i) {
        for (int j = i+1; j < v1.size(); ++j) {
            if (v1[i] == v1[j]) {
                ++ans;
            }
        }
    }
    for (int i = 0; i < v2.size(); ++i) {
        for (int j = i+1; j < v2.size(); ++j) {
            if (v2[i] == v2[j]) {
                ++ans;
            }
        }
    }
    cout << ans;
}
