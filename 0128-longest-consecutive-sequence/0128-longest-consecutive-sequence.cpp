class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int>st;
        for(int i=0;i<nums.size();i++)
        {
            st.insert(nums[i]);
        }   
        int maxLength=0;
        for(auto it:st)
        {
            int count=0;
            if(st.find(it-1)==st.end())
            {
                int num=it;
                while(st.find(num)!=st.end())
                {
                    count++;
                    num++;
                }
            }
            maxLength=max(maxLength,count);
        }
        return maxLength;
        

    }
};