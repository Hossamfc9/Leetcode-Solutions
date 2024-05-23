class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int, int> mp;
        vector<int> a;
        for(int i = 0; i < nums.size(); i++)
        {
            if(mp[target - nums[i]])
            {
                a.push_back(mp[target - nums[i]] - 1);
                a.push_back(i);
            }
            mp[nums[i]] = i + 1;
        }
        return a;
    }
};