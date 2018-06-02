#include <bits/stdc++.h>
using namespace std;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif

    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
    }
    sort(v.begin(), v.end());
    bool b = 1;
    int i = n-1, j = 0;
    while (i > j) {
        if (b) {
            --i;
        } else {
            ++j;
        }
        b = !b;
    }
    cout << v[i];
}
