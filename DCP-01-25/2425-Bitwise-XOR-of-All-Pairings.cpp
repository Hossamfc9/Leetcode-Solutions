class Solution {
public:
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size(), m = nums2.size();
        int temp = 0;
        if(m % 2) {
            for(int i = 0; i < n; i++) {
                temp ^= nums1[i];
            }
        }
        if(n % 2) {
            for(int i = 0; i < m; i++) {
                temp ^= nums2[i];
            }
        }
        return temp;
    }
};