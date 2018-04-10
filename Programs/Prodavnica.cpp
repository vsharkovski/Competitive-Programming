#include <bits/stdc++.h>
using namespace std;

int main()
{
//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);

    //Dynamic programming algorithm (for exercise, I am learning it RN (2018/04/10)))
    int P, V;
    cin >> P >> V;

    int n = V - P;
    vector<int> coins = {1, 2, 5};
    sort(coins.begin(), coins.end());

    int dp[n+1];
    memset(dp, 100000000, sizeof(dp));
    dp[0] = 0;

    for (int amount = 1; amount <= n; ++amount)
    {
        for (int coinValue : coins)
        {
            if (coinValue > amount) break;
            int from = amount - coinValue; //najefikasnoto od prethodna presmetka
            dp[amount] = min(dp[amount], dp[from]+1);
        }
    }

    cout << dp[n];
}


/* EZ solution (Greedy)
#include <bits/stdc++.h>
using namespace std;

int main() {
    int p, v; cin >> p >> v;
    int k = v - p;
    int c = 0;
    int k5a = k / 5, k5b = k % 5;
    c += k5a;
    if (k5b > 0) {
        int k2a = k5b / 2, k2b = k5b % 2;
        c += k2a;
        if (k2b > 0) {
            c += k2b;
        }
    }
    cout << c << endl;
}
*/
