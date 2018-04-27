#include <bits/stdc++.h>
using namespace std;

int main()
{
//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);
    int n, a, b;
    cin >> n >> a >> b;
    string s;
    cin >> s;
    int maxi = 0;
    int prev = 0; //none
    for (int i = 0; i < s.length(); ++i)
    {
        if (s[i] == '*')
        {
            prev = 0;
        }
        else
        {
            if (prev == 'a')
            {
                if (b > 0)
                {
                    prev = 'b';
                    --b;
                    ++maxi;
                }
                else
                {
                    prev = 0;
                }
            }
            else if (prev == 'b')
            {
                if (a > 0)
                {
                    prev = 'a';
                    --a;
                    ++maxi;
                }
                else
                {
                    prev = 0;
                }
            }
            else
            {
                if (a > b)
                {
                    if (a > 0)
                    {
                        prev = 'a';
                        --a;
                        ++maxi;
                    }
                    else
                    {
                        prev = 0;
                    }
                }
                else
                {
                    if (b > 0)
                    {
                        prev = 'b';
                        --b;
                        ++maxi;
                    }
                    else
                    {
                        prev = 0;
                    }
                }
            }
        }
    }
    cout << maxi;

}
