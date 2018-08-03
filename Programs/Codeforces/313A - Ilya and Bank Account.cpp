#include <bits/stdc++.h>
using namespace std;


int main()
{
//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);

    string s;
    cin >> s;
    cout << max( stoi(s), max( stoi(s.substr(0, s.length()-1)), stoi(s.substr(0,s.length()-2)+s.back()) ) );
}
