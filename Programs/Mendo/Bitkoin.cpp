#include <bits/stdc++.h>
using namespace std;


const int MAXN = 300005;

int N;
static int want[MAXN];
vector<int> children[MAXN];
static int depth[MAXN];
static int answer[MAXN];
set<int> data[MAXN];

void depthDFS(int, int);
void dfs(int);
void mergeData(set<int>&, set<int>&, int);
void addToData(set<int>&, int, int);


int main() {
    cin >> N >> want[0];
    ++N;
    for (int i = 1; i < N; ++i) {
        int parent;
        cin >> want[i] >> parent;
        children[parent].push_back(i);
    }
    depthDFS(0, 0);
    dfs(0);
    for (int i = 1; i < N; ++i) {
        cout << answer[i] << '\n';
    }
}

void depthDFS(int u, int currDepth) {
    depth[u] = currDepth;
    for (int v : children[u]) {
        depthDFS(v, currDepth + 1);
    }
}

void dfs(int u) {
    for (int v : children[u]) {
        dfs(v);
        if (data[v].size() > data[u].size()) {
            swap(data[u], data[v]);
        }
        mergeData(data[u], data[v], u);
    }
    addToData(data[u], u, u);
    if (u == 0) {
        // clear the data from 0 (the source), since it has no parent
        while (!data[0].empty()) {
            set<int>::iterator first = data[0].begin();
            answer[*first] = depth[*first] - depth[0];
            data[0].erase(first);
        }
    }
}

void mergeData(set<int>& d1, set<int>& d2, int dfsNode) {
    while (!d2.empty()) {
        addToData(d1, *d2.begin(), dfsNode);
        d2.erase(d2.begin());
    }
}

void addToData(set<int>& d, int x, int dfsNode) {
    d.insert(x);
    set<int>::iterator curr = d.find(x);
    bool removed = false;
    if (curr != d.begin()) {
        // x is not the first element in data
        // elements before x are processed before x
        set<int>::iterator previ = prev(curr);
        if (want[*previ] >= want[x]) {
            // an element before x has a
            // "want value" bigger than the "want value" of x
            // since for this problem the nodes are processed by increasing node number,
            // x will be useless. so remove x
            answer[x] = depth[x] - depth[dfsNode] - 1;
            d.erase(curr);
            removed = true;
        }
    }
    if (removed == false) {
        set<int>::iterator nxt = next(curr); // the element in data after x
        while (nxt != d.end() && want[x] >= want[*nxt]) {
            // the same logic as above, except this time x is the "previous element",
            // and "nxt" has the role of x
            answer[*nxt] = depth[*nxt] - depth[dfsNode] - 1;
            // some tricks to erase "nxt" and then go to the element after it
            set<int>::iterator temp = next(nxt);
            d.erase(nxt);
            nxt = temp;
        }
    }
}
