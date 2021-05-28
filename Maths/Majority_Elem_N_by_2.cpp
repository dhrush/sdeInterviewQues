class Solution {
public:
    int majorityElement(vector<int>& nums) 
    {
        //This better brute but not optimal
        /*int N = nums.size();
        map<int, int> freqMap;
        for(int i=0; i<N; i++)
        {
            freqMap[nums[i]]++;
        }
        
        for(auto it : freqMap)
        {
            if(it.second > N/2)
            {
                return it.first;
            }
        }
        return -1;*/
        
        //optimal approach is Moore's voting algorithm
        int count = 0;
        int elem = 0;
        for(int num : nums)
        {
            if(count == 0)  elem = num;
            if(elem == num) count+=1;
            else    count-=1;
        }
        return elem;       
        
    }
};