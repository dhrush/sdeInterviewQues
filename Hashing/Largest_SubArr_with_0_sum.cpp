int maxLen(int A[], int n)
{
    // Your code here
    //sort(A, A+n);
   /* int maxSize = 0;
    for(int i=0; i<n; i++)
    {
        int instSize = 0;
        int sum = A[i];
        for(int j=i+1; j<n; j++)
        {
            sum += A[j];
            if(sum == 0)
            {
                instSize = j-i+1;
                maxSize = max(maxSize, instSize);
            }
        }
    }
    return maxSize;*/
    
    unordered_map<int,int> prefixSumMap;
    int sum = 0;
    int subArrSize = 0;
    for(int i=0; i<n; i++)
    {
        sum += A[i];
        if(A[i] == 0 && subArrSize == 0)
            subArrSize = 1;
        if(sum == 0)
        {
            subArrSize = i+1;
        }
        else
        {
            if(prefixSumMap.find(sum) != prefixSumMap.end())
            {
                subArrSize = max(subArrSize, i - prefixSumMap[sum]);
            }
            else
            {
                prefixSumMap[sum] = i;
            }
        }
    }
    return subArrSize;
}