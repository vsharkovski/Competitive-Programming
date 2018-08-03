#include <bits/stdc++.h>
using namespace std;


int main()
{
//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);

    set<char> chars;
    string name;
    cin >> name;
    for (char c : name)
    {
        chars.insert(c);
    }
    cout << ((chars.size() % 2 == 0) ? "CHAT WITH HER!" : "IGNORE HIM!");
}
