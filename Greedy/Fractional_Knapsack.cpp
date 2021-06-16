struct Item{
    int value;
    int weight;
};
*/


class Solution
{
    public:
    
    static bool compare(Item a, Item b)
    {
        double r1 = (double)a.value/(double)a.weight;
        double r2 = (double)b.value/(double)b.weight;
        return (r1>r2);
    }
    //Function to get the maximum total value in the knapsack.
    double fractionalKnapsack(int W, Item arr[], int n)
    {
        sort(arr, arr+n, compare);
        
        double maxProfit=0;
        double curWeight=0;
        for(int i=0; i<n; i++)
        {
            if(curWeight + arr[i].weight <= W)
            {
                curWeight += arr[i].weight;
                maxProfit += arr[i].value;
            }
            else
            {
                int remainW = W-curWeight;
                maxProfit += (arr[i].value/(double)arr[i].weight)*(double)remainW;
                break;
            }
        }
        return maxProfit;
    }
        
};
