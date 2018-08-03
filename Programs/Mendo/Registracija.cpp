#include <bits/stdc++.h>
using namespace std;
 
int stoi(string &s) {
    stringstream ss(s);
    int i;
    ss >> i;
    return i;
}
 
int main() {
    map<string, set<int>> m;
    string ts; cin >> ts;
    int n; cin >> n;
    for (int i = 0; i < n; ++i) {
        string s; cin >> s;
        string ns, ids;
        for (int j = 0; j < s.length(); ++j) {
            int ci = s.at(j) - '0';
            if (0 < ci && ci < 10) {
                ns = s.substr(0, j);
                ids = s.substr(j);
                break;
            }
            ns = s;
        }
        if (ids == "") ids = "0";
        m[ns].insert( stoi(ids) );
    }
    if (m[ts].empty()) {
        cout << ts << endl;
    }
    else {
        string ns, ids;
        for (int i = 0; i < ts.length(); ++i) {
            int ci = ts.at(i) - '0';
            if (0 < ci && ci < 10) {
                ns = ts.substr(0, i);
                ids = ts.substr(i);
                break;
            }
            ns = ts;
        }
        if (ids == "") ids = "0";
        int id = stoi(ids);
        bool found = false;
        for (auto it = m[ns].begin(); it != m[ns].end(); ++it) {
            if (*it == id) {
                id++;
            }
            else {
                if (id == 0) cout << ns << endl;
                else cout << ns << id << endl;
                found = true;
                break;
            }
        }
        if (!found) {
            cout << ns << (*prev(m[ns].end())) + 1 << endl;
        }
    }
}
