class Solution {
public:
    static bool isPrefixAndSuffix(string s, string t) {
        int n = s.size(), m = t.size();
        if(n > m) {
            return 0;
        }
        for(int i = 0; i < n; i++) {
            if(s[i] != t[i]) {
                return 0;
            }
        }int diff = m - n;
        for(int j = m; ~(j - diff); j--) {
            if(t[j] != s[j - diff]) {
                return 0;
            }
        }
        return 1;
    }
    int countPrefixSuffixPairs(vector<string>& words) {
        int n = words.size();
        int ans = 0;
        for(int i = 0; i < n; i++) {
            for(int j = i + 1; j < n; j++) {
                ans += isPrefixAndSuffix(words[i], words[j]);
            }
        }
        return ans;
    }
};