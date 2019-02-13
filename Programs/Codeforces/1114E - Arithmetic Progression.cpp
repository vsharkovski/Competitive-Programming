#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
typedef pair<int, int> pi;
typedef vector<int> vi;
template<class Key, class Compare = less<Key>>
using Tree = tree<Key, null_type, Compare, rb_tree_tag, tree_order_statistics_node_update>;





int n;
int queries;
set<int> nums, asked;

int hasbigger(int x) {
    ++queries;
    cout << "> " << x << '\n';
    cout.flush();
    int r;
    cin >> r;
    return r;
}

int getelement(int i) {
    ++queries;
    cout << "? " << i << '\n';
    cout.flush();
    int x;
    cin >> x;
    return x;
}

void Main() {
    cin >> n;
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
    uniform_int_distribution<int> dist(1, n);
    queries = 0;
    int xmax = 0;
    int lo = 0, hi = 1e9, mid;
    while (lo <= hi) {
        mid = (lo + hi) / 2;
        int r = hasbigger(mid);
        if (r == -1) {
            return;
        } else if (r == 0) {
            hi = mid-1;
        } else {
            lo = mid+1;
            xmax = mid+1;
        }
    }
    nums.insert(xmax);
    while (queries < 60 && nums.size() < n) {
        int i;
        do {
            i = dist(rng);
        } while (asked.count(i));
        asked.insert(i);
        nums.insert(getelement(i));
    }
    int d = -1, pr = -1;
    for (int x : nums) {
        if (pr != -1) {
            if (d == -1) {
                d = x - pr;
            } else {
                d = __gcd(d, x - pr);
            }
        }
        pr = x;
    }
    int xmin = xmax - (n-1)*d;
    cout << "! " << xmin << " " << d << '\n';
}

int main() {
//    ios::sync_with_stdio(false);
//    cin.tie(nullptr);
    #ifdef _DEBUG
//        freopen("in.txt", "r", stdin);
//        freopen("out.txt", "w", stdout);
    #endif
    Main();
    return 0;
}
