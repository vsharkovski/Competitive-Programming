#include <bits/stdc++.h>  
using namespace std;  
   
typedef unsigned long long ull;  
   
int main() {  
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);  
   
    int n, k;  
    cin >> n >> k;  
   
    if (k >= n) {  
        cout << 1;  
        return 0;  
    }  
   
    int bestx = -1;  
    ull bestp = ~0;  
    for (int x = 1; x < n; ++x) {  
        ull p = k*x*(x-1)/2 + n/x + (n%x > 0);  
        if (p < bestp) {  
            bestp = p;  
            bestx = x;  
        }  
    }  
    if (k*n*(n-1)/2 + 1 < bestp) {  
        bestx = n;  
    }  
   
//    cout << bestp << ' ';  
    cout << bestx << '\n';  
   
}  
