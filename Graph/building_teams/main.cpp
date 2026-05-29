#include<bits/stdc++.h>
using namespace std;


bool dfsColor(int node, int color, vector<int>&colors, const vector<vector<int>>& adjlist) {
    colors[node] = color;
    for (auto nei : adjlist[node]) {
        if (colors[nei] == -1) {
            bool odd_cycle = dfsColor(nei, 1 - color, colors, adjlist);
            if (odd_cycle == false) return false;
        } else if (colors[nei] == colors[node]) {
            return false;
        }
    }
    return true;
}

int main() {
    int n; // number of nodes
    int m; // number of edges/connections
    cin >> n >> m;

    vector<vector<int>>adjlist(n + 1); // adjacency list

    int u;
    int v;
    // get adjacency list
    for (int i=0;i<m;i++) {
        cin >> u >> v;
        adjlist[u].push_back(v);
        adjlist[v].push_back(u);
    }

    vector<int>colors(n+1,-1); // colors[i] := color of ith node
    for (int node=1; node <= n; node++) {
        if (colors[node] == -1) {
            bool canColor = dfsColor(node,1,colors,adjlist);
            if (canColor == false) {
                cout << "IMPOSSIBLE" << '\n';
                return 0;
            }
        }
    }
    for (int node = 1 ; node <= n ; node++) {
       if (colors[node] == 0) cout << 2; else cout << 1;
       cout << ' ';
    }
    return 0;
}