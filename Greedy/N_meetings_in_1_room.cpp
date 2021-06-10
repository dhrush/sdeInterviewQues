class Solution
{
    public:
    //Function to find the maximum number of meetings that can
    //be performed in a meeting room.
    struct meeting
    {
        int start;
        int end;
        int pos;
    };
    
    static bool comparator(struct meeting m1, meeting m2)
    {
        if(m1.end < m2.end) return true;
        else if(m1.end > m2.end)    return false;
        else if(m1.pos < m2.pos)    return true;
        return false;
    }
    
    int maxMeetings(int s[], int e[], int n)
    {
        if(n==0)    return 0;
        struct meeting meet[n];
        for(int i=0; i<n; i++)
        {
            meet[i].start = s[i];
            meet[i].end = e[i];
            meet[i].pos = i+1;
        }
        int count=0;
        sort(meet, meet+n, comparator);
        int limit = meet[0].end;
        
        for(int i=1; i<n; i++)
        {
            if(meet[i].start > limit)
            {
                limit = meet[i].end;
                count++;
            }
        }
        return count+1;
    }
};