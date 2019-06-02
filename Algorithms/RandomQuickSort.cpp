class Solution {
public:
    int pivot(int start, int end, vector<int> &A)
    {
        int rnd = rand()%(end-start+1);
        swap(A[start+rnd],A[end]);
        int p = A[end];
        int pIdx = start;
        for(int i=start;i<end;++i)
        {
            if(A[i]<=p)
            {
                swap(A[i],A[pIdx]);
                pIdx++;
            }
        }
        swap(A[end],A[pIdx]);
        return pIdx;
        
    }
    void quickSort(int start, int end, vector<int> &arr)
    {
        if(start<end)
        {
            int pIdx = pivot(start,end,arr);
            quickSort(start,pIdx-1,arr);
            quickSort(pIdx+1,end,arr);
        }
    }
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        quickSort(0,n-1,nums);
        
    }
};