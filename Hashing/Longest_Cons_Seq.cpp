class Solution {
public:
    int longestConsecutive(vector<int>& nums) 
    {
        //Brute Force Solution
        //TC = O(NlogN + N)
        //SC = O(N) Since merge sort
        /*
        if(nums.empty())    return 0;
        sort(nums.begin(), nums.end());
        int count = 0;
        int maxSeq = 0;
        for(int i=0; i<nums.size()-1; i++)
        {
            if(nums[i]+1 == nums[i+1])
                maxSeq = max(maxSeq, ++count);
            else if(nums[i] == nums[i+1])
                count = count;
            else 
                count = 0;
        }
        return maxSeq+1;
        */
        
        //Optimal solution
        // TC = O(N)        +     O(N)      +        O(N)
        //      pushing to stack  Traversin vector   Checking the count
        if(nums.empty())    return 0;
        set<int> hashSet;
        for(int num : nums)
            hashSet.insert(num);
        int maxCount = 0;
        for(int i=0; i<nums.size(); i++)
        {
            auto it = hashSet.find(nums[i]-1);
            if(it == hashSet.end())
            {
                int currNum = nums[i];
                int currMax = 1;
                while( hashSet.count(currNum+1) )
                {
                    currNum += 1;
                    currMax += 1;
                }
                maxCount = max(maxCount, currMax);
            }
        }
        return maxCount;
    }
};