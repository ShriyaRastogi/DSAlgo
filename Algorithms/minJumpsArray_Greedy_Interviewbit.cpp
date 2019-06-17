int Solution::jump(vector<int> &A) {
    int n = A.size();
    if(n==0) return -1;
    int jumps=0, end=0, currfar=0;
    for(int i=0;i<n-1;++i)
    {
        currfar = max(currfar, min(i+A[i],n-1));
        if(i==end)
        {
            end = currfar;
            ++jumps;
        }
    }
    if(end!=n-1) return -1;
    return jumps;
    
}
