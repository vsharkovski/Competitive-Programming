#include <bits/stdc++.h>
using namespace std;

int main()
{
//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);

    int n;
    cin >> n;
    int cnt = 0;
    vector<char> a(n);
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    vector<char>::iterator curr, previ = a.begin();
    for (curr = next(previ); curr != a.end(); ++curr)
    {
        if (*curr == *previ)
        {
            a.erase(curr);
            curr = previ;
            ++cnt;
        }
        previ = curr;
    }
    cout << cnt;
}
