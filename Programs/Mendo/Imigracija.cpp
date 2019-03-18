#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pi;
typedef vector<int> vi;



const int maxsize = 10000005;
const int maxn = 100005;
const int maxk = 30005;

int N, K;
int X[maxn], Y[maxn], V[maxn];
int Y1[maxk], Y2[maxk]; // y1 and y2 for each query
int query_result[maxk]; // result for each query
vector<int> x_points[maxsize]; // points to add at x coordinate
vector<pi> x_query_update[maxsize]; // (query id, 0=start/1=end)
ll ft[maxsize]; // for dynamic range sum queries over y

void update(int k, int x) { // add to node for Fenwick tree
    for (; k <= maxsize; k += k & -k) {
        ft[k] += x;
    }
}

ll rsq(int k) { // range sum query for Fenwick tree
    ll res = 0;
    for (; k >= 1; k -= k & -k) {
        res += ft[k];
    }
    return res;
}

ll rsq(int l, int r) {
    return rsq(r) - rsq(l-1);
}

void Main() {
    cin >> N;
    for (int i = 0; i < N; ++i) {
        cin >> X[i] >> Y[i] >> V[i];
        ++X[i], ++Y[i];
        x_points[X[i]].push_back(i);
    }
    cin >> K;
    for (int i = 0; i < K; ++i) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        ++x1, ++y1, ++x2, ++y2;
        Y1[i] = y1, Y2[i] = y2;
        x_query_update[x1 - 1].emplace_back(i, 0);
        x_query_update[x2].emplace_back(i, 1);
    }
    for (int x = 0; x < maxsize; ++x) {
        for (int point : x_points[x]) {
            update(Y[point], V[point]);
        }
        for (auto& q : x_query_update[x]) {
            int i = q.first;
            int status = q.second;
            if (status == 0) { // query start
                query_result[i] -= rsq(Y1[i], Y2[i]);
            } else { // query end
                query_result[i] += rsq(Y1[i], Y2[i]);
            }
        }
    }
    for (int i = 0; i < K; ++i) {
        cout << query_result[i] << '\n';
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    #ifndef _DEBUG
    #endif
    Main();
    return 0;
}
