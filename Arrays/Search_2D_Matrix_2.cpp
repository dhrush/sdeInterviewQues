class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) 
    {
        int i=0;
        int j = matrix[0].size()-1;
        
        bool found = false;
        
        while(i<matrix.size() && j>=0)
        {
            if(matrix[i][j] == target)
            {
                found = true;
                break;
            }
            if(matrix[i][j] > target)
            {
                j--;
            }
            else
                i++;
        }
        return found;
    }
};