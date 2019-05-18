// Maximum cardinality biparite matching
// n: size of left set
// m: size of right set

int n, m;
vector<int> match;
vector<bool> visited;

bool augmented_path(int L) {
    if (visited[L]) return false;
    visited[L] = true;
    for (int R = 0; R < m; ++R) {
        if (blocked[L][R]) continue;
        if (match[R] == -1 || augmented_path(match[R])) {
            match[R] = L;
            return true;
        }
    }
    return false;
}

int bipartite() {
    match.assign(m, -1);
    int cnt = 0;
    for (int L = 0; L < n; ++L) {
        visited.assign(n, false);
        if (augmented_path(L)) {
            // successfully matched
            ++cnt;
        }
    }
    return cnt;
}
