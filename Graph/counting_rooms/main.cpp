#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>


int dx[4] = {0,1,-1,0};
int dy[4] = {1,0,0,-1};

void dfs(
        int x , 
        int y , 
        std::vector<std::vector<bool>> &visited ,
        const std :: vector<std::vector<char>> & matrix
) {
    visited[x][y] = true;
    for (unsigned i = 0 ; i < 4 ; i++) {
        int nei_x = x + dx[i];
        int nei_y = y + dy[i];
        if (nei_x >= 0 && 
            nei_y >= 0 && 
            nei_x < visited.size() && 
            nei_y < visited[0].size() && 
            visited[nei_x][nei_y] == false && 
            matrix[nei_x][nei_y] == '.'
            ) 
        {
                dfs(
                    nei_x,
                    nei_y,
                    visited,
                    matrix
                );
        }
    }
}

int main() {
    int n , m;
    std :: cin >> n >> m;
    std::vector<std::vector<char>>matrix(
        n , std :: vector<char>(m,'#')
    );

    std :: vector <std :: vector<bool>> visited(
        n , 
        std :: vector<bool> (m , false)
    );
    
    std :: queue <std::pair<int,int>>q;
    int rooms = 0;

    for (unsigned i = 0 ; i < n ; i++) {
        for (unsigned j = 0 ; j < m ; j++) {
            std :: cin >> matrix[i][j];
            if (matrix[i][j] == '.') q.push({i,j});
        }
    }

    while (!q.empty()) {
        auto cell = q.front();
        q.pop();
        auto x = cell.first;
        auto y = cell.second;
        if (visited[x][y]) continue;
        dfs(x,y,visited,matrix);
        rooms++;
    }
    
    std :: cout << rooms << std :: endl;

    return 0;
}