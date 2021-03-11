#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int ans = 0;
    for(int i=0;i<5;++i){
        int x;
        cin>>x;
        ans += x/2;
    }
    cout<<ans;
}
