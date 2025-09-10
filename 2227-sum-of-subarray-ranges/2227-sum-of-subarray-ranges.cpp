class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        //maximum sum
        //minimum sum

        vector<int>nse(nums.size(),nums.size());
        vector<int>pse(nums.size(),-1);
        vector<int>nge(nums.size(),nums.size());
        vector<int>pge(nums.size(),-1);

        stack <pair<int,int>>st;

        for(int i=0;i<nums.size();i++)
        {
            while(!st.empty()&&st.top().first>=nums[i])
            {
                st.pop();
            }
            if(!st.empty())
            {
                pse[i]=st.top().second;
            }
            st.push({nums[i],i});
        }
        stack<pair<int,int>>st1;
        for(int i=0;i<nums.size();i++)
        {
            while(!st1.empty()&&st1.top().first<=nums[i])
            {
                st1.pop();
            }
            if(!st1.empty())
            {
                pge[i]=st1.top().second;
            }
            st1.push({nums[i],i});
        }
        stack<pair<int,int>>st2;
         for(int i=nums.size()-1;i>=0;i--)
        {
            while(!st2.empty()&&st2.top().first>nums[i])
            {
                st2.pop();
            }
            if(!st2.empty())
            {
                nse[i]=st2.top().second;
            }
            st2.push({nums[i],i});
        }
        stack<pair<int,int>>st3;
         for(int i=nums.size()-1;i>=0;i--)
        {
            while(!st3.empty()&&st3.top().first<nums[i])
            {
                st3.pop();
            }
            if(!st3.empty())
            {
                nge[i]=st3.top().second;
            }
            st3.push({nums[i],i});
        }


        //minimum sum
        long long total1=0;

        for(int i=0;i<nums.size();i++)
        {
            int left=nse[i]-i;
            int right=i-pse[i];

            total1+=((long long)left*right*nums[i]);

        }
        long long total2=0;
        for(int i=0;i<nums.size();i++)
        {
             int left=nge[i]-i;
            int right=i-pge[i];

            total2+=((long long)left*right*nums[i]);

        }
        

        return total2-total1;
    }
};