class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) 
    {
        if(intervals.size()<=1) return intervals;
        
        vector<vector<int>> op;
        sort(intervals.begin(), intervals.end());
        op.push_back(intervals[0]);
        
        for(int i=1; i<intervals.size(); i++)
        {
            if(op.back()[1] >= intervals[i][0])
                op.back()[1] = max(op.back()[1], intervals[i][1]);
            else
                op.push_back(intervals[i]);
        }
        return op;
    }
};