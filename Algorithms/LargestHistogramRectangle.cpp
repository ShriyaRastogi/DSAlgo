class Solution {
public:
    int largestRectangleArea(vector<int>& arr) {
        if(arr.size()==0) return 0;
        stack<int> st;
        st.push(0);
        int ma = INT_MIN;
        int n = arr.size();
        for(int i=1;i<n;++i)
        {
            int tos = st.top();
            if(arr[i]>arr[tos])
                st.push(i);
            else
            {
                while(true)
                {
                    tos = st.top();
                    st.pop();
                    if(!st.empty()) ma = max(ma, arr[tos]*(i-st.top()-1));
                    else ma = max(ma, arr[tos]*(i));
                    if(st.empty()) break;
                    if(arr[i]>=arr[st.top()]) break;
                }
                st.push(i);
            }
        }
        
        while(!st.empty())
        {
            int tos = st.top();
            st.pop();
            if(!st.empty()) ma = max(ma, arr[tos]*(n-st.top()-1));
            else ma = max(ma,arr[tos]*n);
        }
        
        return ma;
    }
};
