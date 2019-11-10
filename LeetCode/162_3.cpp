class Solution {
public:
    int dx[4] = {0, 0, 1, -1};
    int dy[4] = {-1, 1, 0, 0};
    int visited[100][100];
    int groupnum[100][100];
    int n, m;
    void DFS(int x, int y, vector<vector<int>> &v, int g) {
        visited[x][y] = true;
        groupnum[x][y] = g;
        for (int i = 0 ; i < 4 ; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (0 <= nx && nx < n && 0 <= ny && ny < m) {
                if (v[nx][ny] == 0 && !visited[nx][ny]) {
                    DFS(nx, ny, v, g);
                }
            }
        }
    }
    int closedIsland(vector<vector<int>>& grid) {
        for (int i = 0 ; i < 100 ; i++) {
            for (int j = 0 ; j < 100 ; j++) {
                visited[i][j] = 0;
            }
        }
        n = grid.size();
        m = grid[0].size();
        int group = 0;
        for (int i = 0 ; i < n ;i++) {
            for (int j = 0 ; j < m ;j++) {
                if (grid[i][j] == 0 && !visited[i][j]) {
                    group += 1;
                    DFS(i, j, grid, group);
                }
            }
        }
        int possible[100001];
        for (int i = 0 ; i < 100000 ; i++) {
            possible[i] = 0;
        }
        for (int i = 1 ; i <= group ; i++) {
            possible[i] = 1;
        }
        //printf("%d\n", group);
        for (int i = 0 ; i < n ; i++) {
            for (int j = 0 ; j < m ; j++) {
                if (i == 0 || i == n - 1 || j == 0 || j == m-1) {
                    possible[groupnum[i][j]] = 0;
                }
            }
        }
        int answer = 0;
        for (int i = 1 ; i <= group ; i++) {
            if (possible[i]) {
                answer += 1;
            }
        }
        return answer;
    }
};