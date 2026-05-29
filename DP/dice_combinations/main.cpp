#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    const int MOD = 1000000007;

    vector<long long> dp(n + 1, 0);
    // dp[i] : number of ways to construct the sum 'i' using dice (1-6 numbered)
    dp[0] = 1; // base initialization


    for (int i = 1; i <= n; i++) {
        for (int dice = 1; dice <= 6; dice++) {
            if (i - dice >= 0) {
                dp[i] = (dp[i] + dp[i - dice]) % MOD;
            }
        }
    }

    // answer
    cout << dp[n] << endl;

    return 0;
}