#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

/*
TASK: gift1
LANG: C++
*/

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    freopen("gift1.in", "r", stdin);
    freopen("gift1.out", "w", stdout);

    int n;
    cin >> n;

    vector<string> name(n);
    map<string, int> id;

    for (int i = 0; i < n; ++i) {
        cin >> name[i];
        id[name[i]] = i;
    }

    vector<int> balance(n, 0);

    for (int idx = 0; idx < n; ++idx) {
        string giver;
        int amount, people;
        cin >> giver >> amount >> people;
        int i = id[giver];
        balance[i] -= amount;
        if (people > 0) {
            int single = amount / people;
            balance[i] += amount % people;
            while (people--) {
                string receiver;
                cin >> receiver;
                int j = id[receiver];
                balance[j] += single;
            }
        }
    }

    for (int i = 0; i < n; ++i) {
        cout << name[i] << ' ' << balance[i] << '\n';
    }

}
