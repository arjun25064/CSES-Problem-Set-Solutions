#include<bits/stdc++.h>
using namespace std;

int main() {
    int n; // number of vertices
    int m; // number of edges/connections

    cin >> n >> m;
    
    vector<vector<int>>adjlist(n+1); // adjacency list (n+1 for 1-based node indexing)
    
    int u;
    int v;
    // building adjacency list
    for (int i=0;i<m;i++) {
        cin >> u >> v;
        adjlist[u].push_back(v);
        adjlist[v].push_back(u);
    }

    vector<int>parent(n+1); // parent array
    vector<bool>visited(n+1,false); // visited array
    for (int i=0;i<=n;i++) parent[i]=i;
    
    queue<pair<int,int>>q; // queue - to be used for bfs , tracks {node,dist} ie bfs depth
    q.push({1,0}); 
    visited[1]=true;
    int final_dist = -1;
    
    // bfs from node=1
    while (!q.empty()) {
        auto front = q.front();
        auto node = front.first;
        auto dist = front.second;
        q.pop();
        if (node == n) {
            // reached target node
            final_dist = dist;
            break;
            // ..
        }

        // visit neighbour nodes 
        for (auto nei : adjlist[node]) {
            if (visited[nei] == false) {
                visited[nei]=true;
                q.push({nei,dist+1});
                parent[nei]=node;
            }
        }
    }

    if (final_dist == -1) {
        // impossible to reach target node
        cout << "IMPOSSIBLE" << '\n';
    } else {
        cout << final_dist + 1 << '\n';
        vector<int>path;
        int node = n;
        while (node != 1) {
            path.push_back(node);
            node = parent[node];
        }
        path.push_back(1);
        
        for (auto it = path.rbegin() ; it != path.rend() ; it++) 
            cout << *it << " ";
        
    }

    return 0;
}