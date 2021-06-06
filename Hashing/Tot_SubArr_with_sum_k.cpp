class Solution {
public:
    int subarraySum(vector<int>& nums, int k) 
    {
        //brute force 
        /*int count = 0;
        for (int start = 0; start < nums.size(); start++) {
            for (int end = start + 1; end <= nums.size(); end++) {
                int sum = 0;
                for (int i = start; i < end; i++)
                    sum += nums[i];
                if (sum == k)
                    count++;
            }
        }
        return count;*/
        //using hasmap prefix sum technique 
        int len = nums.size();
        int ans = 0;
        unordered_map<int, int> sumCnt;
        sumCnt[0]++;
        int sum = 0;
        for (int i = 0; i < len; i++)
        {
            sum += nums[i];
            if (sumCnt.count(sum - k)) ans += sumCnt[sum-k];
            sumCnt[sum]++;
        }
        return ans;   
    }
};