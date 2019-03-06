   
#include <bits/stdc++.h>
using namespace std;


struct Tuple {
    int a, b;
    Tuple(int _a, int _b) : a(_a), b(_b) {}
    Tuple() {}
};

void getnew(multiset<int>& s, vector<int>& v) {
    while (!s.empty()) {
        for (auto it = s.begin(); it != s.end();) {
            v.push_back(*it);
            auto nxt = s.upper_bound(*it);
            s.erase(it);
            it = nxt;
        }
    }
}

void strangeSort(vector<Tuple>& v) {
    map<int, multiset<int>> data;
    for (auto& x : v) {
        data[x.a].insert(x.b);
    }
    v.clear();
    for (auto& kvp : data) {
        vector<int> res;
        getnew(kvp.second, res);
        for (auto& x : res) {
            v.emplace_back(kvp.first, x);
        }
    }
}

   
int main() {
    int n;
    cin >> n;
    vector<Tuple> v(n);
    for (auto& tuple : v) {
        cin >> tuple.a >> tuple.b;
    }
    
    strangeSort(v);
    for (auto& val : v) {
        cout << val.a << " " << val.b << "\n";
    }
    return 0;
}
