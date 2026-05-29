// #include <bits/stdc++.h>
// using namespace std;


////  ***** MY SOLUTION ****************

// bool contains_digit(int num , int digit) {
//     while (num) {
//         if (num % 10 == digit) return true;
//         num /= 10;
//     }
//     return false;
// }

// int func(int n) {
//     if (n == 0) return 0;
//     if (n <= 9) return 1;
//     vector<int>dp(n+1,INT_MAX);
//     dp[0]=0;
//     for (int i = 1 ; i <= 9 ; i++) dp[i]=1;
//     for (int num = 10 ; num <= n ; num++) {
//         for (int digit = 1 ; digit <= 9 ; digit++) {
//             if (contains_digit(num , digit) == true) {
//                 dp[num] = min(dp[num] , 1 + dp[num - digit]);
//             }
//         }
//     }
//     return dp[n];
// }


// int main() {
//     int n;
//     cin >> n;
//     cout << func(n);
//     return 0;
// }


#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> dp(n + 1, INT_MAX);
    dp[0] = 0;

    for (int i = 1; i <= n; i++) {
        int x = i;

        while (x) {
            int d = x % 10;
            x /= 10;

            if (d != 0) {
                dp[i] = min(dp[i], 1 + dp[i - d]);
            }
        }
    }

    cout << dp[n] << endl;
}