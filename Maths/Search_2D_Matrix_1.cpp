class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) 
    {
        //following gives soln in TC = O(n) + O(logm)
        /*int row = 0;
        int cols = matrix[0].size();
        for(int i=0; i<matrix.size(); i++)
        {
            if(target <= matrix[i][cols-1])
            {
                row = i;
                break;
            }
        }
        
        bool found = binary_search(matrix[row].begin(), matrix[row].end(), target);
        return found;*/
        
        int n = matrix.size();
        int m = matrix[0].size();
        
        bool found = false;
        
        int lo = 0;
        int high = (m*n) - 1;
        
        while(lo <= high)
        {
            int mid = (high + lo)/2;
            if(matrix[mid/m][mid%m] == target)
            {
                found = true;
                break;
            }
            else if(matrix[mid/m][mid%m] > target)  high = mid - 1;
            else    lo = mid + 1;
        }
        
        return found;        
    }
};_