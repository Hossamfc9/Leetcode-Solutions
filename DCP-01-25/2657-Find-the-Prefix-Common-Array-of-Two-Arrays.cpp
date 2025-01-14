class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int n = A.size();
        vector<int> c(n);
        unordered_map<int, int> mp;
        for(int i = 0; i < n; i++) {
            ++mp[A[i]];
            for(int j = 0; j <= i; j++) {
                c[i] += mp[B[j]];
            }
        }
        return c;
    }
};