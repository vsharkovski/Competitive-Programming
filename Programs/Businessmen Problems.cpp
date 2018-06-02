#include <bits/stdc++.h>
using namespace std;

struct Z {
    int x = -1;
    int y = -1;
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif

    int n;
    cin >> n;
    map<int, Z> ceni;
    for (int i = 0; i < n; ++i) {
        int a, x;
        cin >> a >> x;
        ceni[a].x = x;
    }
    int m;
    cin >> m;
    for (int i = 0; i < m; ++i) {
        int b, y;
        cin >> b >> y;
        ceni[b].y = y;
    }
    long long maxi = 0;
    for (auto it = ceni.begin(); it != ceni.end(); ++it) {
        maxi += max(it->second.x, it->second.y);
    }
    cout << maxi;
}
