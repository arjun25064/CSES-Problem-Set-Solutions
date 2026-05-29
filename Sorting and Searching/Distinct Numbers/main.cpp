#include<bits/stdc++.h>
using namespace std;

int main() {
    int n; // number of integers
    cin >> n;
    vector<long long>nums(n);
    
    set<long long>st;
    for (int i=0;i<n;i++) {
        cin >> nums[i];
        st.insert(nums[i]);
    }
    cout << st.size();
    return 0;
}