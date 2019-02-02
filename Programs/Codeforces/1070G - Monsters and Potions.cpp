#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
typedef pair<int, int> pi;
typedef vector<int> vi;
template<class Key, class Compare = less<Key>>
using Tree = tree<Key, null_type, Compare, rb_tree_tag, tree_order_statistics_node_update>;



void Main() {
    int n, m;
    cin >> n >> m;
    vector<pi> heroes;
    for (int i = 0; i < m; ++i) {
        int s, h;
        cin >> s >> h;
        --s;
        heroes.emplace_back(s, h);
    }
    vector<int> board(n);
    for (int i = 0; i < n; ++i) {
        cin >> board[i];
    }
    for (int rally = 0; rally < n; ++rally) {
        vector<int> taken(n, 0);
        vector<int> board1 = board;
        vector<int> order;
        int numtaken = 0;
        while (numtaken < m) {
            bool did = false;
            for (int i = 0; i < m; ++i) {
                if (taken[i] == 0) {
                    int p = heroes[i].first, h = heroes[i].second;
                    while (p != rally) {
                        if (p < rally) {
                            ++p;
                        } else {
                            --p;
                        }
                        h += board1[p];
                        if (h < 0) {
                            break;
                        }
                    }
                    if (p == rally && h >= 0) {
                        did = true;
                        ++numtaken;
                        taken[i] = 1;
                        order.push_back(i);
                        p = heroes[i].first;
                        while (p != rally) {
                            if (p < rally) {
                                ++p;
                            } else {
                                --p;
                            }
                            board1[p] = 0;
                        }
                    }
                }
            }
            if (!did) {
                break;
            }
        }
        if (numtaken == m) {
            cout << rally+1 << '\n';
            for (int x : order) {
                cout << x+1 << ' ';
            }
            cout << '\n';
            return;
        }
    }
    cout << "-1\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    #ifdef _DEBUG
//        freopen("in.txt", "r", stdin);
//        freopen("out.txt", "w", stdout);
    #endif
    Main();
    return 0;
}
