class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        int n = words1.size(), m = words2.size();
        vector<string> ans;
        vector<vector<int>> f(n, vector<int>(26));
        vector<int> temp(26);
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < words1[i].size(); j++) {
                ++f[i][words1[i][j] - 'a'];
            }
        }
        for(int i = 0; i < m; i++) {
            vector<int> cur(26);
            for(int j = 0; j < words2[i].size(); j++) {
                ++cur[words2[i][j] - 'a'];
            }
            for(int j = 0; j < 26; j++) {
                temp[j] = max(temp[j], cur[j]);
            }
        }
        for(int i = 0; i < n; i++) {
            bool ok = 1;
            for(int j = 0; j < 26; j++) {
                if(f[i][j] < temp[j]) {
                    ok = 0;
                }
            }
            if(ok)
                ans.push_back(words1[i]);
        }
        return ans;
    }
};