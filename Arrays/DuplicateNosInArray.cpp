class Solution {
public:
    int findDuplicate(vector<int>& nums) 
    {
        int slow = nums[slow];
        int fast = nums[fast];
        
        do
        {
            slow = nums[slow];
            fast = nums[nums[fast]];            
        }while(slow!=fast);
            
        fast = nums[0];
        while(fast!=slow)
        {
            fast = nums[fast];
            slow = nums[slow];
        }
        
        return slow;
        
    }
};

//leetcode link https://leetcode.com/problems/find-the-duplicate-number/