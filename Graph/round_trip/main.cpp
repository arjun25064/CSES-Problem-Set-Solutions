#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> adjlist;
vector<int> parent;
vector<bool> visited;

int start_node = -1, end_node = -1;

bool dfs(int node , int par)
{
    visited[node] = true;
    for (const auto &nei : adjlist[node])
    {
        if (nei == par)
            continue;

        if (visited[nei])
        {
            start_node = nei;
            end_node = node;
            return true;
        }

        parent[nei] = node;

        if (
            dfs(nei,node))
        {
            return true;
        }
    }
    return false;
}

int main()
{

    int n, m;
    cin >> n >> m;

    adjlist.resize(n + 1);
    visited.resize(n + 1, false);
    parent.resize(n + 1, -1);

    int u, v;
    for (int i = 0; i < m; i++)
    {
        cin >> u >> v;
        adjlist[u].push_back(v);
        adjlist[v].push_back(u);
    }

    for (int node = 1; node <= n; node++)
    {
        if (!visited[node] and dfs(node,-1))
        {
            break;
        }
    }

    if (start_node == -1)
    {
        cout << "IMPOSSIBLE" << endl;
    }
    else
    {
        vector<int>cycle;
        cycle.push_back(start_node);
        for (int node = end_node ; node != start_node ; node = parent[node]) {
            cycle.push_back(node);
        }
        cycle.push_back(start_node);

        cout << cycle.size() << endl;

        for (const auto &i : cycle) {
            cout << i << " ";
        }
        cout << "\n";
    }

    return 0;
}