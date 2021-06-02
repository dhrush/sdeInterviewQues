class Solution 
{
public:
    vector<int> twoSum(vector<int>& nums, int target) 
    {
        unordered_map<int,int> iMap;
        vector<int> ans;
        for(int i=0; i<nums.size(); i++)
        {
            auto it = iMap.find(target - nums[i]);
            if (it != iMap.end())
            {
                ans = vector<int> {i, it->second};
                return ans;
            }
            iMap[nums[i]] = i;
        }
        return ans;
    }
};