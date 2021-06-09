class Solution {
public:
    int trap(vector<int>& a) 
    {
        //brute force
        /*
            water stored at ith index = min(max_left(i), max_right(i)) - a[i]
            max_left(i) = max value from 0 to i
            max_right(i) = max value from i to n-1
            
            TC = O(n^2) SC = O(1)
        
        int sum = 0;
        for(int i=0; i<height.size(); i++)
        {
            int max_left = *max_element(height.begin(), height.begin()+i+1);
            int max_right = *max_element(height.begin()+i, height.end());
            
            sum += min(max_left, max_right) - height[i];
        }
        return sum;*/
        
        //better
        /*
        using leftmax vector 
        and rightmax vector
        TC = O(n)+O(n)+O(n) SC=O(n)+O(n)
        
        int n = height.size();
        int sum=0;
        if(!n) return sum;
        vector<int> prefixLeft(n,0);
        vector<int> prefixRight(n,0);
        
        int maxLeftHeight=0;
        int maxRightHeight=0;
        
        prefixLeft[0] = height[0];
        
        for(int i=1 ; i<n; i++)
            prefixLeft[i] = max(prefixLeft[i-1], height[i]);
        
        prefixRight[n-1] = height[n-1];
        
        for(int i = n - 2 ; i >= 0; i--)
            prefixRight[i] = max(prefixRight[i+1], height[i]);
        
        for(int i=0; i<n; i++)
            sum += min(prefixLeft[i], prefixRight[i]) - height[i];
        
        return sum;*/
        
        //best
        int l = 0;
        int r = a.size()-1;
        int leftMax = 0;
        int rightMax = 0;
        int res=0;
        while(l<=r)
        {
            if(a[l] <= a[r])
            {
                if(a[l]>=leftMax)   leftMax = a[l];
                else    res += leftMax - a[l];
                
                l++;
            }
            else
            {
                if(a[r]>=rightMax)  rightMax=a[r];
                else    res+=rightMax-a[r];
                    
                r--;
            }
        }
        return res;
        
    }
};