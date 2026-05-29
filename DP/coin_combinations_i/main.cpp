#include<bits/stdc++.h>
using namespace std;

int main() {
    long long n , x;
    cin >> n >> x;

    const int MOD = 1000000007;
    vector<long long>coins(n);
    vector<long long>dp(x+1,0);
    for (long long i=0;i<n;i++) {
        cin >> coins[i];
    }

    dp[0]=1;
    for (int i=1;i<=x;i++) {
        for (auto j : coins) {
            if (i - j >= 0) {
                dp[i] = (dp[i] + dp[i - j]) % MOD;
            }
        }
    }
    cout << dp[x] << endl;

    return 0;
}