class Solution {
public:
    int n, m;
    int countServers(vector<vector<int>>& grid) {
        n = grid.size(), m = grid[0].size();
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