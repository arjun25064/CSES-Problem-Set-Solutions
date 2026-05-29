#include<bits/stdc++.h>
using namespace std;


void bfs(
        int node, 
        const vector<vector<int>>& adjlist, 
        vector<bool>& visited
        ) 
{
    queue<int>q;
    q.push(node);
    visited[node]=true;
    while (!q.empty()) {
        auto node = q.front();
        q.pop();
        for (auto nei : adjlist[node]) {
            if (visited[nei] == false) {
                visited[nei]=true;
                q.push(nei);
            }
        }
    }
}

int main() {
    int n;
    int m;
    cin >> n >> m;
    vector<vector<int>> adjlist(n+1); 
    
    int u,v;
    for (int i=0;i<m;i++) {
        cin >> u >> v;
        adjlist[u].push_back(v);
        adjlist[v].push_back(u);
    }

    vector<bool>visited(n+1,false);
    vector<int>leaders;
    for (int node=1;node<=n;node++) {
        if (visited[node] == false) {
            leaders.push_back(node);
            bfs(node,adjlist,visited);
        }
    }

    int k = leaders.size() - 1;
    if (k == 0) {
        cout << k;
    } else {
       cout << k << "\n";
       for (int i=1;i<=k;i++) {
            cout << leaders[i - 1] << " " << leaders[i] << "\n";
       }
    }
    
    return 0;
}