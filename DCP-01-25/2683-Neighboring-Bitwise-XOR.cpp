class Solution {
public:
    bool doesValidArrayExist(vector<int>& derived) {
        int n = derived.size();
        int cur = 0;
        int cnt = 0;
        for(int i = 0; i < n; i++) {
            if(derived[i]) {
                ++cur;
            }
            else {
                cnt += (cur % 2);
                cur = 0;
            }
        }
        cnt += cur % 2;
        return (cnt % 2 == 0);
    }
};