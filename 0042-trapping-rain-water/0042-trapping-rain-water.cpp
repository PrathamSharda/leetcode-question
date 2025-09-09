class Solution {
public:
    int trap(vector<int>& height) {
        stack<int>st;
        for(int i=height.size()-1;i>=0;i--)
        {
            if(st.empty())
            {
                st.push(height[i]);
            }else{
                if(height[i]<st.top())
                {
                    continue;
                }else{
                    st.push(height[i]);
                }
            }
        }
        int left=height[0];
        int total=0;
        for(int i=0;i<height.size();i++)
        {
            if(height[i]<left&&height[i]<st.top())
            {
                total+=min(left,st.top())-height[i];
            }
            if(height[i]>left)
            {
                left=height[i];
            }
            if(height[i]>=st.top())
            {
                st.pop();
            }
        }

        return total;

    }
};