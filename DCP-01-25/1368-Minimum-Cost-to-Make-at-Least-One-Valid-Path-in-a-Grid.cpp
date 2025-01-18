class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> dp(n, vector<int>(m, 1e9));
        dp[0][0] = 0;
        int cnt = 0;
        while(cnt <= 1000) {
            for(int i = 0; i < n; i++) {
                for(int j = 0; j < m; j++) {
                    if(i) {
                        dp[i][j] = min(dp[i][j], dp[i - 1][j] + (grid[i - 1][j] != 3));
                    }
                    if(j) {
                        dp[i][j] = min(dp[i][j], dp[i][j - 1] + (grid[i][j - 1] != 1));
                    }
                }
            }
            for(int i = n - 1; ~i; i--) {
                for(int j = m - 1; ~j; j--) {
                    if(i < n - 1) {
                        dp[i][j] = min(dp[i][j], dp[i + 1][j] + (grid[i + 1][j] != 4));
                    }
                    if(j < m - 1) {
                        dp[i][j] = min(dp[i][j], dp[i][j + 1] + (grid[i][j + 1] != 2));
                    }
                }
            }
            ++cnt;
        }
        return dp[n - 1][m - 1];
    }
};