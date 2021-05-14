class Solution {
public:
    void sortColors(vector<int>& nums) 
    {
        //using ducth national flag algorithm
        // 3 way partioning
        
        int low=0;
        int mid=0;
        int n=nums.size();
        int high=n-1;
        
        while(mid<=high)
        {
            switch(nums[mid])
            {
                case 0:
                    swap(nums[low++], nums[mid++]);
                    break;
                    
                case 1:
                    mid++;
                    break;
                    
                case 2:
                    swap(nums[mid], nums[high--]);
                    break;
            }
        }
        
    }
};