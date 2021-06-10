class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) 
    {
        int maxCount=0;
        int curCount=0;
        int i=0; 
        while(i<nums.size())
        {
            if(nums[i]==1)
            {
                curCount++;                
            }
            else
            {
                curCount=0;
            }
            maxCount = max(maxCount, curCount);
            i++;
        }
        return maxCount;
                    
    }
};