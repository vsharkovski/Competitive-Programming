#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
 
 
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<ll> arr(n), pre(n), nxt(n);
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
    {
        priority_queue<ll, vector<ll>, greater<ll>> pq;
        ll sum = 0;
        int cnt = 0;
        for (int i = 0; i < n; ++i) {
            ++cnt;
            if (pq.empty() || (int)pq.size() < n/3) {
                sum += arr[i];
                pq.push(arr[i]);
            } else if (pq.top() < arr[i]) {
                sum -= pq.top();
                pq.pop();
                sum += arr[i];
                pq.push(arr[i]);
            }
            pre[i] = sum;
            if (i > 0 && cnt-1 >= n/3) pre[i] = max(pre[i], pre[i-1]);
        }
    }
    {
        priority_queue<ll, vector<ll>, less<ll>> pq;
        ll sum = 0;
        int cnt = 0;
        for (int i = n-1; i >= 0; --i) {
            ++cnt;
            if (pq.empty() || (int)pq.size() < n/3) {
                sum += arr[i];
                pq.push(arr[i]);
            } else if (pq.top() > arr[i]) {
                sum -= pq.top();
                pq.pop();
                sum += arr[i];
                pq.push(arr[i]);
            }
            nxt[i] = sum;
            if (i+1 < n && cnt-1 >= n/3) nxt[i] = min(nxt[i], nxt[i+1]);
        }
    }
    ll ans = -1e18;
    int cntL = 0, cntR = n;
    for (int i = 0; i < n; ++i) {
        ++cntL, --cntR;
        //cout<<"i="<<i<<" pre="<<pre[i]<<" nxt="<<nxt[i]<<" ";
        if (cntL >= n/3 && cntR >= n/3) {
            //cout<<"good";
            ans = max(ans, pre[i] - nxt[i+1]);
        }
        //cout<<"\n";
    }
    cout << ans << '\n';
}
