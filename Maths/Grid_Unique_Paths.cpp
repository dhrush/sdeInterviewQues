class Solution {
public:
    
    /*int countPath(int i, int j, int m, int n, vector<vector<int>> &dp)
    {
        This is DP Solution
        if(i==m-1 && j==n-1) return 1;
        if(i>=m || j>=n)    return 0;
        if(dp[i][j]!=-1)    return dp[i][j];
        else    
        {
            dp[i][j] = countPath(i+1, j, m, n, dp) + countPath(i, j+1, m, n, dp);
            return dp[i][j];
        }
    }*/
    
    int uniquePaths(int m, int n) 
    {
        /*
        int i = 0; 
        int j = 0;
        vector<vector<int>> dp(-1);
        int count = countPath(i, j, m, n, dp);
        return count;
        */
        
        
        //This is optimal solution using combinatorics
        int N = m+n-2;
        int r = m-1;
        double res = 1;
        for(int i=1; i<=r; i++)
        {
            res = res*(N-r+i)/i;
        }
        return int(res);
    }
};