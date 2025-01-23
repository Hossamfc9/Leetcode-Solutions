class Solution {
public:
    int n, m;
    vector<vector<bool>> vis;
    vector<vector<int>> grid;
    int dx[4] = {0, 0, 1, -1};
    int dy[4] = {1, -1, 0, 0};

    bool valid(int i, int j) {
        return i >= 0 && i < n && j >= 0 && j < m && grid[i][j] == 1;
    }

    int dfs(int i, int j) {
        int cnt = 1;
        vis[i][j] = 1;
        for(int k = 0; k < 4; k++) {
            int newi = i + dx[k];
            int newj = j + dy[k];
            if(valid(newi, newj) && !vis[newi][newj]) {
                cnt += dfs(newi, newj);
            }
        }
        return cnt;
    }
    int countServers(vector<vector<int>>& grid) {
        this->grid = grid;
        n = grid.size(), m = grid[0].size();
        vis = vector<vector<bool>>(n, vector<bool> (m));
        int ans = 0;
        vector<int> row(n);
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                row[i] += grid[i][j];
            }
        }
        vector<int> col(m);
        for(int j = 0; j < m; j++) {
            for(int i = 0; i < n; i++) {
                col[j] += grid[i][j];
            }
        }
        for(int i = 0; i < m; i++) {
            if(col[i] > 1) {
                ans += col[i];
            }
            else {
                for(int j = 0; j < n; j++) {
                    if(grid[j][i] == 1) {
                        if(row[j] > 1) {
                            ++ans;
                            break;
                        }
                    }
                }
            }
        }
        return ans;
    }
};