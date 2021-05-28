class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) 
    {
        int num1 = -1;
        int num2 = -1;
        int c1=0;
        int c2=0;
        int N = nums.size();
        for(int elem : nums)
        {
            if(num1 == elem)    c1++;
            else if(num2 == elem)   c2++;
            else if(c1 == 0)
            {
                num1 = elem;
                c1++;
            }
            else if (c2 == 0)
            {
                num2 = elem;
                c2++;
            }
            else
            {
                c1--;
                c2--;
            }
        }
        vector<int> ans;
        c1=c2=0;
        for(int i:nums)
        {
            if(i == num1)   c1++;
            if(i == num2)   c2++;
        }
        if(c1>N/3)  ans.push_back(num1);
        if(c2>N/3)  ans.push_back(num2);
        return ans;
    }
};