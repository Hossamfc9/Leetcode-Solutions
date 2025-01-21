class Solution {
public:
    long long gridGame(vector<vector<int>>& grid) {
        int n = 2, m = grid[0].size();
        vector<vector<long long>> grd(n, vector<long long> (m));
        grd[0][0] = grid[0][0];
        grd[1][0] = grid[1][0];
        for(int i = 0; i < n; i++) {
            for(int j = 1; j < m; j++) {
                grd[i][j] = grid[i][j] + grd[i][j - 1];
            }
        }
        int temp = m - 1;
        long long ans = LONG_LONG_MAX;
        for(int j = 0; j < m; j++) {
            ans = min(ans, max(grd[0][m - 1] - grd[0][j], (j ? grd[1][j - 1] : 0)));
        }
        return ans;
    }
};