#include <bits/stdc++.h>
using namespace std;


int main() {

    int n , m;
    cin >> n >> m; // grid size


    // input grid
    vector<string>grid(n);
    for (int i=0;i<n;i++) {
        cin >> grid[i];
    }

    const int INF = 1e9;
    vector<vector<int>> monster_time(
        n,
        vector<int>(m,INF)
    );

    // monster_time[i][j] :=
    // minimim time required for a monster to arrive at cell (i,j)

    queue<pair<int,int>>q;
    pair<int,int>start;
    for (int i = 0 ; i < n ; i++) {
        for (int j = 0 ; j < m ; j++) {
            if (grid[i][j] == 'M') {
                q.push({i,j});
                monster_time[i][j] = 0;
            }
            if (grid[i][j] == 'A') {
                start = {i,j};
            }
        }
    }
    vector<int>dx = {1,-1,0,0};
    vector<int>dy = {0,0,1,-1};

    // bfs from monsters
    while (!q.empty()) {
        auto c = q.front();
        auto x =  c.first , y = c.second;
        q.pop();

        for (int d = 0 ; d < 4 ; d++) {

            int nx = x + dx[d];
            int ny = y + dy[d];

            if (
                nx >= 0 and nx < n and ny >= 0 and ny < m and 
                grid[nx][ny] != '#'
            ) {
                if (monster_time[nx][ny] > monster_time[x][y] + 1) {
                    monster_time[nx][ny] = monster_time[x][y] + 1;
                    q.push({nx,ny});
                }
            }
        }
    }

    vector<vector<int>> dist(n, vector<int>(m,-1));
    vector<vector<char>> parent(n, vector<char>(m));
    
    queue<pair<int,int>>player;
    player.push(start);
    dist[start.first][start.second] = 0;

    vector<char> dir = {'D' , 'U' , 'R' , 'L'};

    while (!player.empty()) {
        auto t = player.front();
        auto x = t.first , y = t.second;
        player.pop();

        // if reached boundary cell
        if (x == 0 || y == 0 || x == n - 1 || y == m - 1) {
            string path;
            while (make_pair(x , y) != start) {
                char c = parent[x][y];
                path.push_back(c);
                if (c == 'D') x--;
                else if (c == 'U') x++;
                else if (c == 'R') y--;
                else if (c == 'L') y++;
            }
            reverse(path.begin(),path.end());
            cout << "YES\n";
            cout << path.size() << "\n";
            cout << path << "\n";
            return 0;
        }

        for (int d = 0 ; d < 4 ; d++) {
            int nx = x + dx[d];
            int ny = y + dy[d];

            if (
                nx >= 0 and nx < n and 
                ny >= 0 and ny < m and
                grid[nx][ny] != '#'
            ) {
                if (dist[nx][ny] == -1) {
                    int next_time = dist[x][y] + 1;
                    if (
                        next_time < monster_time[nx][ny]
                    ) {
                        dist[nx][ny] = next_time;
                        parent[nx][ny] = dir[d];
                        player.push({nx,ny});
                    }
                }
            }
        }
    }
    cout << "NO\n";

    return 0;
}