#include <bits/stdc++.h>
using namespace std;
  
int main()
{
    int n;
    cin >> n;
    int n1 = n, n2 = 0;
    while (n1 != 0) {
        n2 = 10 * n2 + (n1 % 10);
        n1 /= 10;
    }
    cout << max(n, n2);
}
