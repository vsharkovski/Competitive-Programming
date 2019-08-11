#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef pair<int, int> pii;
 
void __print(int x) {cerr << x;}
void __print(long x) {cerr << x;}
void __print(long long x) {cerr << x;}
void __print(unsigned x) {cerr << x;}
void __print(unsigned long x) {cerr << x;}
void __print(unsigned long long x) {cerr << x;}
void __print(float x) {cerr << x;}
void __print(double x) {cerr << x;}
void __print(long double x) {cerr << x;}
void __print(char x) {cerr << '\'' << x << '\'';}
void __print(const char *x) {cerr << '\"' << x << '\"';}
void __print(const string &x) {cerr << '\"' << x << '\"';}
void __print(bool x) {cerr << (x ? "true" : "false");}
 
template<typename T, typename V>
void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ','; __print(x.second); cerr << '}';}
template<typename T>
void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i: x) cerr << (f++ ? "," : ""), __print(i); cerr << "}";}
void _print() {cerr << "]\n";}
template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}
#ifndef ONLINE_JUDGE
#define debug(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define debug(x...)
#endif
 
 
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int n;
    cin >> n;
    vector<pii> edges;
    for (int i = 1; i < n; ++i) {
        edges.emplace_back(i, i+1);
    }
    edges.emplace_back(n, 1);
    int p = n;
    while (true) {
        bool ok = true;
        for (int q = 2; q*q <= p; ++q) {
            if (p % q == 0) {
                ok = false;
                break;
            }
        }
        if (ok) {
            break;
        }
        ++p;
    }
    vector<int> deg(n+1, 2);
    for (int i = 1; i <= n; ++i) {
        if (p == n) {
            break;
        }
        if (deg[i] != 2) continue;
        int j = ((i-1)+2)%n + 1;
        edges.emplace_back(i, j);
        ++deg[i], ++deg[j];
        --p;
    }
    cout << edges.size() << endl;
    for (auto& p : edges) {
        cout << p.first << ' ' << p.second << endl;
    }
}
