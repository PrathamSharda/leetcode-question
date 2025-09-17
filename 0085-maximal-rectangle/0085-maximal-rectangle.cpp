class Solution {
public:
    int maxAreaHist(vector<int>&arr)
    {
        vector<int>nse(arr.size(),arr.size());
        vector<int>pse(arr.size(),-1);
        stack<pair<int,int>>st;
        for(int i=0;i<arr.size();i++)
        {
            while(!st.empty()&&st.top().first>=arr[i])st.pop();

            if(!st.empty())
            {
                pse[i]=st.top().second;
            }
            st.push({arr[i],i});
        }
        stack<pair<int,int>>st1;
         for(int i=arr.size()-1;i>=0;i--)
        {
            while(!st1.empty()&&st1.top().first>=arr[i])st1.pop();

            if(!st1.empty())
            {
                nse[i]=st1.top().second;
            }
            st1.push({arr[i],i});
        }
        int maxArea=0;
        for(int i=0;i<arr.size();i++)
        {
            int area=arr[i]*(nse[i]-pse[i]-1);
            maxArea=max(area,maxArea);
        }
        return maxArea;

    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        vector<vector<int>>temp(matrix.size(),vector<int>(matrix[0].size(),0));
        for(int i=0;i<temp.size();i++)
        {
            for(int j=0;j<temp[0].size();j++)
            {
                if(matrix[i][j]=='1')temp[i][j]=1;
            }
        }

        for(int i=1;i<temp.size();i++)
        {
            for(int j=0;j<temp[0].size();j++)
            {
                if(temp[i][j]==0)continue;
                temp[i][j]+=temp[i-1][j];
            }
        }
        int maxArea=0;

        for(auto it:temp)
        {
            int area=maxAreaHist(it);
            maxArea=max(maxArea,area);

        }
        return maxArea;
    }
};