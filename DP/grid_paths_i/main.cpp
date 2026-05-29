// #include<bits/stdc++.h>
// using namespace std;

// int main() {
//     int n;
//     cin >> n;
//     char grid[n][n];
//     for (int i=0;i<n;i++) {
//         for (int j=0;j<n;j++) {
//             cin >> grid[i][j];
//         }
//     }

//     vector<vector<long long>> dp(n,vector<long long>(n,0)); 
//     // 2D dp array
//     // dp[i][j] = number of ways to reach cell (i,j)
//     const int MOD = 1000000007;
//     if (grid[0][0] == '.') dp[0][0]=1;
//     for (int j=1;j<n;j++) {
//         if (grid[0][j] == '*') 
//             dp[0][j]=0;
//         else 
//             dp[0][j]=dp[0][j-1];
        
//         if (grid[j][0] == '*') 
//             dp[j][0]=0;
//         else 
//             dp[j][0]=dp[j-1][0];
//     }

//     for (int i=1;i<n;i++) {
//         for (int j=1;j<n;j++) {
//             if (grid[i][j] == '*') 
//                 dp[i][j]=0;
//             else 
//                 dp[i][j] = (dp[i-1][j] + dp[i][j-1]) % MOD;
//         }
//     }

//     cout << dp[n-1][n-1];

//     return 0;   
// }

#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    char grid[n][n]; 
    for (int i=0;i<n;i++) {
        for (int j=0;j<n;j++) {
            cin >> grid[i][j];
        }
    }

    vector<long long>prev(n,0); // represents previous row
    vector<long long>curr(n,0); // represents current row
    const int MOD = 1000000007;

    if (grid[0][0] == '.') prev[0]=1;
    for (int j=1;j<n;j++) {
        if (grid[0][j] == '*') 
            prev[j]=0;
        else 
            prev[j]=prev[j-1];
    }

    for (int i=1;i<n;i++) {
        
        if (grid[i][0] == '*') curr[0]=0;
        else curr[0]=prev[0];

        for (int j=1;j<n;j++) {
            if (grid[i][j] == '*') {
                curr[j]=0;
            } else {
                curr[j] = (prev[j] + curr[j-1]) % MOD;
            }
        }
        prev = curr;
    }
    
    cout << prev[n-1];
    return 0;
}