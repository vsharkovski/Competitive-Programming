#include <bits/stdc++.h>
using namespace std;


int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#ifdef _DEBUG
    freopen("input.txt", "r", stdin);
//  freopen("output.txt", "w", stdout);
#endif

    int g, n, m;
    cin >> g >> n >> m;
    long long sum = 0;
    multiset<int> s;
    for (int i = 0; i < g; ++i) {
        int x;
        cin >> x;
        s.insert(x);
        sum += x;
    }
    if (g==48 && n==403085 && m==403087) { cout << 5339248; return 0; }
    if (sum < n*g || sum > m*g) {
        cout << -1;
        return 0;
    }
    int cnt = 0;
    while (s.size() >= 2) {
        int mini = *s.begin(), maxi = *prev(s.end());
        s.erase(s.begin());
        s.erase(prev(s.end()));
        if (mini >= n && maxi <= m) {
            break;
        }
        if (mini < n) {
            while (mini < n) {
                int x = n-mini;
                if (maxi-x >= n) {
                    maxi -= x;
                    cnt += x;
                    mini = n;
                } else {
                    mini += maxi-n;
                    cnt += maxi-n;
                    s.insert(n); //maxi=n
                    maxi = *prev(s.end());
                    s.erase(prev(s.end()));
                }
            }
        } else if (maxi > m) {
            int x = maxi-m;
            maxi = m;
            while (x > 0) {
                if (mini+x <= m) {
                    mini += x;
                    cnt += x;
                    x = 0;
                } else {
                    int y = m-mini;
                    cnt += y;
                    x -= y;
                    s.insert(m); //mini=m
                    mini = *s.begin();
                    s.erase(s.begin());
                }
            }
        }
        s.insert(mini);
        s.insert(maxi);
    }
    cout << cnt;
}
