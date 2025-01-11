class Solution {
public:
    bool canConstruct(string s, int k) {
        int n = s.size();
        unordered_map<char, int> mp;
        for(int i = 0; i < n; i++) {
            ++mp[s[i]];
        }
        int odd = 0;
        for(auto i : mp) {
            odd += (i.second % 2);
        }
        return (n >= k) && (odd <= k);
    }
};