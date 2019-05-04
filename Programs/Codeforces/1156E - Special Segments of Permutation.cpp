#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;



const int inf = 1e9;
const int maxn = 200010;

int n;
int p[maxn];
int pinv[maxn];
int leftborder[maxn];
int rightborder[maxn];

int main() {
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> p[i];
        pinv[p[i]] = i;
    }
    p[0] = p[n+1] = 1e9;
    stack<int> s;
    s.push(0);
    for (int i = 1; i <= n; ++i) {
        while (p[s.top()] < p[i]) {
            s.pop();
        }
        leftborder[i] = s.top() + 1;
        s.push(i);
    }
    while (!s.empty()) {
        s.pop();
    }
    s.push(n+1);
    for (int i = n; i >= 1; --i) {
        while (p[i] > p[s.top()]) {
            s.pop();
        }
        rightborder[i] = s.top() - 1;
        s.push(i);
    }
    int ans = 0;
    for (int i = 1; i <= n; ++i) {
        // let i-th element be the max
        // l < i < r
        // max(p[leftborder[i]], p[leftborder[i]+1], ..., p[rightborder[i]]) = p[i]
        if (i - leftborder[i] < rightborder[i] - i) {
            for (int l = i-1; l >= leftborder[i]; --l) {
                int r = pinv[p[i] - p[l]];
                if (i < r && r <= rightborder[i]) {
                    ++ans;
                }
            }
        } else {
            for (int r = i+1; r <= rightborder[i]; ++r) {
                int l = pinv[p[i] - p[r]];
                if (leftborder[i] <= l && l < i) {
                    ++ans;
                }
            }
        }
    }
    cout << ans << '\n';
}
