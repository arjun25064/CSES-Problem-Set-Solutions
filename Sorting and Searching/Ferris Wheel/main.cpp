#include<bits/stdc++.h>
using namespace std;

int main() {
    int n; // number of children
    long long x; // weight limit 

    cin >> n >> x;

    vector<long long>p(n); // p[i] := weight of ith child
    for (int i=0;i<n;i++) {
        cin >> p[i];
    }

    sort(p.begin(), p.end()); // sort all weights

    int i=0; // two pointers
    int j=n-1;
    int count=0; // number of gondalas required

    // move both pointers towards each other
    while (i < j) {
        // if ith and jth child can fit
        if (p[i] + p[j] <= x) {
            count++; // increment the count
            i++; // move both
            j--;
        } else {
            // else increment and move only j
            count++;
            j--;
        }
    }
    if (i == j) count++; // if there remains a child
    cout << count;
    return 0;
}