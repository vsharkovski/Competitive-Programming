// My attempt at a solution. I don't know graphs as of right now

#include <bits/stdc++.h>
using namespace std;

map<int, set<int>> dists;
vector<set<int>> groups;


void explore1(int n, int gi) {
    auto g = &(groups[gi]); //set pointer
    if (g->find(n) != g->end()) //already in group
        return;

    auto d = &(dists[n]);
    for (auto it = g->begin(); it != g->end(); ++it) {
        if (d->find(*it) == d->end()) { //everyone must be neighbors
            return;
        }
    }

    g->insert(n);

    for (auto it = d->begin(); it != d->end(); ++it) {
        explore1(*it, gi);
    }
}

void explore(int n) {
    set<int> g;
    g.insert(n);
    groups.push_back(g);
    int gi = groups.size()-1;

    auto d = &(dists[n]);
    for (auto it = d->begin(); it != d->end(); ++it) {
        explore1(*it, gi);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
//#ifdef _DEBUG
//	freopen("input.txt", "r", stdin);
////	freopen("output.txt", "w", stdout);
//#endif

    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
    }
    sort(v.begin(), v.end());

    int maxdist = v.back() - v[0];
    int drzac = 1;
    for (int d = 0; d < 32 && drzac <= maxdist; ++d) {
        for (int broj : v) {
            int broj2 = broj+drzac;
            if (binary_search(v.begin(), v.end(), broj2)) {
                dists[broj].insert(broj2);
                dists[broj2].insert(broj);
            }
        }
        drzac = drzac << 1;
    }

    for (int x : v) {
        explore(x);
    }

    int maxsz = -1, maxszi = 0;
    for (int i = 0; i < groups.size(); ++i) {
        int sz = groups[i].size();
        if (sz > maxsz) {
            maxsz = sz;
            maxszi = i;
        }
    }
    cout << maxsz << "\n";
    for (auto x : groups[maxszi]) {
        cout << x << " ";
    }

}
