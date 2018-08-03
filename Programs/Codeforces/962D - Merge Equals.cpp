// 962D
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);

    int n;
    cin >> n;
    map<ll, set<int>> occ;
    for (int i = 0; i < n; ++i)
    {
        ll a;
        cin >> a;
        occ[a].insert(i);
    }

    map<int, ll> result;

    auto it = occ.begin();
    while (!occ.empty())
    {
        it = occ.begin();
        set<int> &ind = it->second;
        int a = it->first;
        if (ind.size() > 1)
        {
            int i1 = *ind.begin();
            ind.erase(ind.begin());
            int i2 = *ind.begin();
            ind.erase(ind.begin());
            occ[a+a].insert(i2);

//            vector<int> r1(n, 0);
//            for (auto z = occ.begin(); z!=occ.end(); ++z)
//            {
//                for (auto q = z->second.begin(); q != z->second.end(); ++q)
//                {
//                    r1[*q] = z->first;
//                }
//            }
//            for (int z : r1)
//                if (z == 0) cout << ". ";
//                else cout << z << ' ';
//            cout << endl;
        }
        else
        {
            if (ind.size() == 1)
            {
                result[*(ind.begin())] = a;
            }
            occ.erase(it);
        }
    }

    cout << result.size() << endl;
    for (auto it = result.begin(); it != result.end(); ++it)
    {
        cout << it->second << " ";
    }
}
