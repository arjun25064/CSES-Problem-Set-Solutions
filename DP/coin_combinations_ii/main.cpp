#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    int x;
    cin >> n >> x;
    vector<int>coins(n);
    for (int i=0;i<n;i++) cin >> coins[i];
    
    vector<long long>dp(x+1,0);
    const int MOD = 1000000007;
    dp[0]=1;
    for (int i=0;i<n;i++) {
        for (int j=coins[i];j<=x;j++) {
            dp[j] = (dp[j] + dp[j-coins[i]]) % MOD;
        }
    }
    cout << dp[x];
    return 0;
}