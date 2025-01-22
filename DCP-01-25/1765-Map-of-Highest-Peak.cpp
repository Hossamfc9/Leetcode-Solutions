class Solution {
public:
    int n, m;
    bool valid(int i, int j) {
        return i >= 0 && i < n && j >= 0 && j < m;
    }
    vector<vector<int>> highestPeak(vector<vector<int>>& v) {
        n = v.size(), m = v[0].size();
        vector<vector<int>> ans(n, vector<int>(m, 1e9));
        queue<pair<int, int>> q;
        
        int dx[4] = {0, 0, 1, -1};
        int dy[4] = {1, -1, 0, 0};
        auto bfs = [&]() {
            vector<vector<int>> vis(n, vector<int>(m));
            while(!q.empty()) {
                int w = q.size();
                for(int s = 0; s < w; s++) {
                    auto [i, j] = q.front();
                    q.pop();
                    if(v[i][j]) {
                        ans[i][j] = 0;
                    }
                    if(vis[i][j]) {
                        continue;
                    }
                    vis[i][j] = 1;
                    for(int k = 0; k < 4; k++) {
                        int newi = i + dx[k];
                        int newj = j + dy[k];
                        if(valid(newi, newj)) {
                            if(!vis[newi][newj]) {
                                q.push({newi, newj});
                            }
                            ans[i][j] = min(ans[i][j], ans[newi][newj] + 1);
                        }
                    }
                }
            }
        };
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(v[i][j]) {
                    q.push({i, j});
                }
            }
        }
        bfs();
        return ans;
    }
};