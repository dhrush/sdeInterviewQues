class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) 
    {
        vector<vector<int>> res;
        if(nums.empty())    return res;
        
        int n = nums.size();
        sort(nums.begin(), nums.end());
        
        for(int i=0; i<n; i++)
    {
            for(int j=i+1; j<n; j++)
            {
                int t0 = target - nums[i]-nums[j];
                int left = j+1;
                int right = n-1;
                while(left<right)
                {
                    int twoSum = nums[left] + nums[right];
                    if(twoSum < t0) left++;
                    else if(twoSum > t0)    right--;
                    else if(twoSum == t0)
                    {                    
                        vector<int> quad(4, 0);
                        quad[0] = nums[i];
                        quad[1] = nums[j];
                        quad[2] = nums[left];
                        quad[3] = nums[right];
                        //auto it = find(res.begin(), res.end(), quad);
                        //if()
                        res.push_back(quad);
                                              
                        //processing duplicaes
                        while(left<right && nums[left]==quad[2])    ++left;
                        while(left<right && nums[right]==quad[3])   --right;
                    }
                }
                //escaping duplicate j
                while(j+1<n && nums[j+1]==nums[j])  j++;
            }
            while(i+1<n && nums[i+1]==nums[i]) ++i;
        }        
        return res;
    }
};