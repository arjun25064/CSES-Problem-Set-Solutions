#include<bits/stdc++.h>
using namespace std;

int main() {
    int n , m;
    cin >> n >> m;
    int arr[n + 1];
    int pos[n + 2];
    pos[0]=0;
    pos[n+1] = n + 1;
    for (int i=1;i<=n;i++) {
        cin >> arr[i];
        pos[arr[i]] = i;
    }

    int r = 1;
    for (int i = 2 ; i <= n ; i++) {
        if (pos[i] < pos[i - 1]) r++;
    }


    while (m--) {
        int i , j;
        cin >> i >> j;
        if (i > j) swap(i , j);

        int x = arr[i] , y = arr[j];

        if (pos[x + 1] > i and pos[x + 1] < j) r++;
        if (pos[x - 1] > i and pos[x - 1] < j) r--;
        if (pos[y + 1] > i and pos[y + 1] < j) r--;
        if (pos[y - 1] > i and pos[y - 1] < j) r++;
        
        if (x == (y + 1)) r--;
        if (x == (y - 1)) r++;

        cout << r << '\n';
        swap(arr[i] , arr[j]);
        pos[x] = j;
        pos[y] = i;
    }

    return 0;
} 
