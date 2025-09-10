class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        vector<int>nse(arr.size(),arr.size());
        vector<int>pse(arr.size(),-1);
        stack<pair<int,int>>st;
        for(int i=0;i<arr.size();i++)
        {
            while(!st.empty()&&st.top().first>=arr[i])
            {
                st.pop();
            }
            if(!st.empty())
            {
                pse[i]=st.top().second;
            }
            st.push({arr[i],i});
        }
        stack<pair<int,int>>st1;
        for(int i=arr.size()-1;i>=0;i--)
        {
            while(!st1.empty()&&st1.top().first>arr[i])
            {
                st1.pop();
            }
            if(!st1.empty())
            {
                nse[i]=st1.top().second;
            }
            st1.push({arr[i],i});
        }

        int total=0;

        for(int i=0;i<arr.size();i++)
        {

            int left=1;
            int right=1;

                left=i-pse[i];

                right=nse[i]-i;

            total=(total+(long long)(left*right)*arr[i])%1000000007;
        }
    return total;
    }
};