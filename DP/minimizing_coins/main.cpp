#include<bits/stdc++.h>
using namespace std;

int main() {
    long long n,target_amt;
    cin >> n >> target_amt;
    
    vector<long long> coins(n);
    for (int i=0;i<n;i++) {
        cin >> coins[i];
    }

    vector<long long>dp(target_amt+1,INT_MAX);
    dp[0]=0;
    for (long long i=1;i<=target_amt;i++) {
        for (auto c : coins) {
            if (i - c >= 0) {
                dp[i] = min(dp[i] , 1 + dp[i - c]);
            }
        }
    }
    // cout << dp[target_amt];
    cout << (dp[target_amt] == INT_MAX ? -1 : dp[target_amt]) << endl;


    return 0;   
}