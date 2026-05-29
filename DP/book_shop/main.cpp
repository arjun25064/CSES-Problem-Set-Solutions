#include <bits/stdc++.h>
using namespace std;

int main() {
    /*
        n : number of books
        x : maximum total price
    */

    // step 1 : define subproblem
    // For each possible amount of money, what is the maximum pages I can get?
    // dp[j] := maximum pages we can get with total price <= j

    // step 2 : recursive formula
    /*
         dp[j] = max(
                dp[j] , 
                pages[i] + dp[j - price[i]]
            );
    */
   
    // step 3 : memo structure


    // step 4 : how to fill memo


    // step 5 : final answer

    int n,x;
    cin >> n >> x;
    vector<int>price(n);
    vector<int>pages(n);
    for (int i=0;i<n;i++) cin >> price[i];
    for (int i=0;i<n;i++) cin >> pages[i];
    vector<int>dp(x+1,0);

    for(int i=0;i<n;i++) {
        for (int j=x;j>=price[i];j--) {
            dp[j] = max(
                dp[j] , 
                pages[i] + dp[j - price[i]]
            );
        }
    }

    cout << dp[x];
    return 0;
}