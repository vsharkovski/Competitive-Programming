#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
//#ifdef _DEBUG
//	freopen("input.txt", "r", stdin);
////	freopen("output.txt", "w", stdout);
//#endif

    int n, k;
    cin >> n >> k;
    set<int> s;
    map<int, int> m;
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        s.insert(x);
        m[x] = i;
    }
    if (s.size() < k) {
        cout << "NO";
    } else {
        cout << "YES\n";
        int i = 0;
        for (auto it = s.begin(); it != s.end() && i < k; ++it) {
            cout << m[*it]+1 << " ";
            ++i;
        }
    }


}
