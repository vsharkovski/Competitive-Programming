#include <bits/stdc++.h>
using namespace std;

bool comp(char c1, char c2)
{
    return tolower(c1) < tolower(c2);
}

int main()
{
//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);

    string s1, s2;
    cin >> s1 >> s2;
    int result;
    for (int i = 0; i < s1.length(); ++i)
    {
        char c1 = s1[i], c2 = s2[i];
        if (tolower(c1) < tolower(c2))
        {
            result = -1;
            break;
        }
        else if (tolower(c1) > tolower(c2))
        {
            result = 1;
            break;
        }
        else
        {
            result = 0;
        }
    }
    cout << result;
}
