#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; // number of applicants
    int m; // number of apartments
    long long k; // max allowed diff
    int count=0;
    cin >> n >> m >> k;

    vector<long long>applicants(n);
    vector<long long>apartments(m);

    for (long long i=0;i<n;i++) {
        cin >> applicants[i];
    } 

    for (long long i=0;i<m;i++) {
        cin >> apartments[i];
    }

    std::sort(applicants.begin(), applicants.end());
    std::sort(apartments.begin(), apartments.end());
    int i=0; // pointer on applicants
    int j=0; // pointer on apartments
    while (i<n && j<m) {

        if(std::abs(applicants[i]-apartments[j])<=k) {
            // if falls in range
            count++; // increment count 
            i++; // increment both pointers
            j++;
        }
        else if(applicants[i] + k > apartments[j]) {
            j++; // applicant_size + k > apartment_size => increment j pointer
        } else {
            i++; // else increment i pointer 
        }
    }
    cout << count;
    return 0;
}