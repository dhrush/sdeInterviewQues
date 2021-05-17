//https://leetcode.com/problems/global-and-local-inversions/

class Solution {
public:
    
    long long int merger(vector<int>& nums, vector<int>& temp, int left, int mid,int right)
    {
        int i=left;
        int j=mid;
        int k=left;
        long long int inversion_count=0;
        while(i<=mid-1 && j<=right)
        {
            if(nums[i]<nums[j])
            {
                temp[k++] = nums[i++];
            }
            else
            {
                temp[k++] = nums[j++];
                inversion_count += mid-i;
            }
        }
        
        while(i<=mid-1)
        {
            temp[k++] = nums[i++];
        }
        
        while(j<=right)
        {
            temp[k++]=nums[j++];
        }
        
        for(int i=left; i<=right; i++)
        {
            nums[i] = temp[i];
        }
        
        return inversion_count;
    }
    
    long long int mergeSort(vector<int>& nums, vector<int>& temp, int left, int right)
    {
        int mid=0;
        long long int inversion_count=0;
        if(right>left)
        {
            mid = (left+right)/2;
            inversion_count += mergeSort(nums, temp, left, mid);
            inversion_count += mergeSort(nums, temp, mid+1, right);
            
            inversion_count += merger(nums, temp, left, mid+1, right);
        }
        
        return inversion_count;
    }
    
    bool isIdealPermutation(vector<int>& nums) 
    {
        int n = nums.size();
        vector<int> temp(n);
        long long int local_count=0;
        for(int i=0; i<n-1; i++)
        {
            if(nums[i]>nums[i+1])
            {
                local_count++;
            }
        }
        long long int inversion_count = mergeSort(nums, temp, 0, n-1);
        
        if(inversion_count == local_count)  return true;
        else return false;
    }
};