class Solution {
public:
    int removeDuplicates(vector<int>& nums) 
    {
        //Brute using hashset does not allow duplicates
        //insert all elements into hashset
        /*set<int> hashSet;
        for(int i=0; i<nums.size(); i++)  hashSet.insert(nums[i]);
        auto it = hashSet.begin();
        for(int i=0; i<hashSet.size(); i++)
        {
            if (i!=0)   advance(it, 1);
            nums[i] = *it;                
        }
        return hashSet.size();*/
        
        //best
        int i=0;
        int j=i+1;
        int n = nums.size();
        if(n==0)    return 0;
        for(int j=1; j<n; j++)
        {
            if(nums[i]!=nums[j])
            {
                i++;
                nums[i]=nums[j];
            }
        }
        return i+1;
    }
};