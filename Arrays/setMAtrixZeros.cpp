class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        bool isZeroCol = false;
        bool isZeroRow = false;
        for (int i = 0; i < matrix.size(); i++) { //check the first column
            if (matrix[i][0] == 0) {
                isZeroCol = true;
                break;
            } 
        }
        for (int i = 0; i < matrix[0].size(); i++) { //check the first row
            if (matrix[0][i] == 0) {
                isZeroRow = true;
                break;
            } 
        }
        for (int i = 1; i < matrix.size(); i++) { //check except the first row and column
            for (int j = 1; j < matrix[0].size(); j++) 
                if (matrix[i][j] == 0) {
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
        }
        for (int i = 1; i < matrix.size(); i++) { //process except the first row and column
           for (int j = 1; j < matrix[0].size(); j++) 
               if (matrix[i][0] == 0 || matrix[0][j] == 0)
                   matrix[i][j] = 0;
        }
        if (isZeroCol) { //handle the first column
            for (int i = 0; i < matrix.size(); i++) 
                matrix[i][0] = 0;
        }
        if (isZeroRow) { //handle the first row
            for (int i = 0; i < matrix[0].size(); i++) 
                matrix[0][i] = 0;
        }
    }
};

//very basic brute force approach
class Solution {
public:
    
    void rearrange(vector<vector<int>>& a, int nRows, int nCols, int iR, int iJ)
    {
        for(int i=0; i<nRows; i++)
        {
            a[i][iJ] = 0;
        }
        
        for(int j=0; j<nCols; j++)
        {
            a[iR][j] = 0;
        }
    }
    
    void setZeroes(vector<vector<int>>& matrix) 
    {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<tuple<int, int>> positions;
        
        for(int i=0;i <m; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(matrix[i][j] == 0)
                {
                    positions.push_back(make_tuple(i,j));
                }
            }
        }
        
        for(int i=0; i<positions.size(); i++)
        {
            int iR = get<0>(positions[i]);
            int iJ = get<1>(positions[i]);
            rearrange(matrix, m ,n, iR, iJ);
        }
        
    }
};