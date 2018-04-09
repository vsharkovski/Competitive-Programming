#include <bits/stdc++.h>
using namespace std;
  
int main()
{
    int n;
    cin >> n;
    int n1 = n+1;
    int brD = n1*(n1+1)/2;
    int vk = 0;
    for (int i = 0; i <= n; ++i) {
        int toc = (i+1)*i + i*(i+1)/2;
        vk += toc;
    }
    cout << vk << endl;
}