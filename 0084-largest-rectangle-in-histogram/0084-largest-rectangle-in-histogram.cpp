class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        vector<int>nse(heights.size(),heights.size());
        vector<int>pse(heights.size(),-1);

        stack<pair<int,int>>st;

        for(int i=0;i<heights.size();i++)
        {
            while(!st.empty()&&st.top().first>=heights[i])
            {
                st.pop();
            }
            if(!st.empty())
            {
                pse[i]=st.top().second;
            }
            st.push({heights[i],i});

        }
        stack<pair<int,int>>st2;
        for(int i=heights.size()-1;i>=0;i--)
        {
            while(!st2.empty()&&st2.top().first>=heights[i])
            {
                st2.pop();
            }
            if(!st2.empty())
            {
                nse[i]=st2.top().second;
            }
            st2.push({heights[i],i});

        }
        int maxArea=0;
        for(int i=0;i<heights.size();i++)
        {
            int area=heights[i]*(nse[i]-pse[i]-1);
           
            maxArea=max(area,maxArea);
        }
        return maxArea;
    }
};