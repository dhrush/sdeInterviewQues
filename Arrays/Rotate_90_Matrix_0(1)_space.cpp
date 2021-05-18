class Solution {
public:
    void rotate(vector<vector<int>>& matrix) 
    {
        int nRows = matrix.size();
        int nCols = matrix[0].size();
        
        //transpose the matrix
        for(int i=0; i<nRows; i++)
        {
            for(int j=i; j<nCols; j++)
            {
                swap(matrix[i][j], matrix[j][i]);
            }
        }
        
        //reverse the columns
        for(int i=0,j=nCols-1; i<=j; i++,j--)
        {
            for(int k=0; k<nRows; k++)
            {
                swap(matrix[k][i], matrix[k][j]);
            }
        }
        
    }
};