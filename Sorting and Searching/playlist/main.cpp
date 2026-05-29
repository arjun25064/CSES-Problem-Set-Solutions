#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    vector<int> arr(n);
    for(int i = 0; i < n; i++)
        cin >> arr[i];

    unordered_map<int,int> last;
    last.reserve(n); // important optimization

    int i = 0;
    int ans = 0;

    for(int j = 0; j < n; j++) {

        if(last.count(arr[j])) {
            i = max(i, last[arr[j]] + 1);
        }

        last[arr[j]] = j;

        ans = max(ans, j - i + 1);
    }

    cout << ans;
}