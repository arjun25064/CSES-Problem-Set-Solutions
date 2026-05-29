#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    int m;
    cin >> n >> m; // n * m grid 
    char grid[n][m]; 
    
    pair<int,int>start(2,-1); // represents start coordinates ie cell containing 'A' 
    pair<int,int>end(2,-1); // represents end coordinates ie cell containing 'B'

    // input grid
    for (int i=0;i<n;i++) {
        for (int j=0;j<m;j++) {
            cin >> grid[i][j];
            if (grid[i][j] == 'A') {
                start.first=i;
                start.second=j;
            } 
            else 
            if (grid[i][j] == 'B') {
                end.first=i;
                end.second=j;
            }
        }
    }   

    vector<vector<bool>>visited(n,vector<bool>(m,false)); // visited matrix
    vector<vector<char>>move_taken(n,vector<char>(m)); // move_taken[i][j] := denotes the previous movement taken from some cell to reach the cell (i,j)
    // this movement could be {'R','L','D','U'} denoting right,left,down,up
    
    queue<vector<pair<int,int>>>q; 
    string final_path = "";
    
    int dx[4] = {1,0,-1,0}; // represent the directions in which we can move from a cell
    int dy[4] = {0,1,0,-1};
    char dir[4] = {'D', 'R', 'U', 'L'};

    q.push({start,start}); 
    visited[start.first][start.second]=true;
    move_taken[start.first][start.second] = '$';
    bool found_path = false;


    // bfs loop
    while (!q.empty()) {
        auto front = q.front();
        auto cell = front[0];
        auto parent = front[1];
        q.pop();

        auto x = cell.first;
        auto y = cell.second;
        
        // if reached target, exit loop 
        if (grid[x][y] == 'B') {
            found_path = true;
            break;
        }   
        
        // try all 4 direction from current cell
        for (int i=0;i<4;i++) {
            auto nx = x + dx[i];
            auto ny = y + dy[i];
            if ( nx >= 0 && nx < n && ny >= 0 && ny < m && visited[nx][ny] == false && grid[nx][ny] != '#') {
                move_taken[nx][ny] = dir[i];
                q.push({{nx,ny},{x,y}});
                visited[nx][ny]=true; // mark as visited
            }    
        }
        
    }

    // if path was found reconstruct the path using move_taken matrix
    if (found_path == true) {
        
        int x = end.first;
        int y = end.second;
        
        while (move_taken[x][y] != '$') {
          final_path += move_taken[x][y];  
          switch(move_taken[x][y]) {
            case 'R':
                y = y - 1;
                break;
            case 'L':
                y = y + 1;
                break;
            case 'D':
                x = x - 1;
                break;
            case 'U':
                x = x + 1;
                break;
          }  

        }
        reverse(final_path.begin(), final_path.end());
        cout << "YES" << "\n";
        cout << final_path.size() << "\n";
        cout << final_path;
    } else {
        cout << "NO";
    }

}