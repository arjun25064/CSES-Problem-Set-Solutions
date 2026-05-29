#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int>a(n);
    map<int,int>mp;
    for (int i=0;i<n;i++) {
        cin >> a[i];
        mp[a[i]]=i;
    }
    int total_rounds = 0;
    int prev_index = -1;
    int num = 1;
    while (num != n + 1) {
        if (prev_index == -1 || mp[num] < prev_index) {
            total_rounds += 1;
        }   
        prev_index = mp[num];
        num += 1;
    }
    cout << total_rounds;
    return 0;
}