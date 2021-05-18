//https://leetcode.com/problems/best-time-to-buy-and-sell-stock/submissions/
class Solution {
public:
    int maxProfit(vector<int>& prices) 
    {
        int minimal_element=INT_MAX;
        int max_profit = 0;
        //keep track of minimal element on left side
        for(int i=0; i<prices.size(); i++)
        {
            if(prices[i]<minimal_element)
            {
                minimal_element = prices[i];
            }
            
            if(prices[i] - minimal_element > max_profit)
            {
                max_profit = prices[i] - minimal_element;
            }
        }
        
        return max_profit;
        
    }
};