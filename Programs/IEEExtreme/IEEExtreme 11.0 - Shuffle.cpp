#include <bits/stdc++.h>
using namespace std;

const int N = 210;

int n;
vector<int> adj[N];
int match[N];
bool visited[N];

bool augmented_path(int i) {
    if (visited[i]) return false;
    visited[i] = true;
    for (int j : adj[i]) {
        if (match[j] == -1 || augmented_path(match[j])) {
            match[j] = i;
            return true;
        }
    }
    return false;
}

int main() {
    cin >> n;
    cin.ignore();
    for (int i = 0; i < n; ++i) {
        string line;
        getline(cin, line);
        stringstream ss(line);
        int j;
        memset(visited, false, sizeof(visited));
        visited[i] = true;
        while (ss >> j) {
            visited[j] = true;
        }
        for (j = 0; j < n; ++j) {
            if (!visited[j]) {
                adj[i].push_back(j);
                // cout << char('A' + i) << " - " << j << endl;
            }
        }
        match[i] = -1;
    }
    int matches = 0;
    for (int i = 0; i < n; ++i) {
        memset(visited, false, sizeof(visited));
        if (augmented_path(i)) {
            ++matches;
        }
    }
    // for (int j = 0; j < n; ++j) {
    //     if (match[j] != -1) {
    //         cout << "matched " << char(match[j] + 'A') << " - " << j << endl;
    //     }
    // }
    cout << n - matches << endl;
}
