class Solution {
public:
    void nextPermutation(vector<int>& nums) 
    {
        int inx;// = INT_MIN;
        int iny;// = INT_MIN;
        int n = nums.size();
        
        for(int i=n-2; i>=0; i--)
        {
            if(nums[i] < nums[i+1])
            {
                inx = i;
                break;
            }
        }
        
        
        if(inx>=0)
        {
            for(int i = n-1; i>=0; i--)
            {
                if(nums[i] > nums[inx])
                {
                    iny = i;
                    break;
                }
            }
            
            swap(nums[inx], nums[iny]);
            reverse(nums.begin()+inx+1, nums.end());
        }
        else
        {
            reverse(nums.begin(), nums.end());      
        }    
    }
};