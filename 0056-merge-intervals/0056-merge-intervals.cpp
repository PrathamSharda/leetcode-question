class Solution {
public:
    static bool compare(vector<int>&a,vector<int>&b)
    {
        
        return a[0]<b[0];
    }
    vector<vector<int>> merge(vector<vector<int>>& intervals) 
    {
        sort(intervals.begin(),intervals.end(),compare);
        // for(auto it:intervals){
        //     cout<<it[0]<<" "<<it[1]<<endl;
        // }
        int left=intervals[0][0];
        int right=intervals[0][1];
        vector<vector<int>>output;
        for(int i=1;i<intervals.size();i++)
        {
            int start=intervals[i][0];
            int end=intervals[i][1];

            if(start<=right)
            {
                right=max(right,end);
            }
            else{
                output.push_back({left,right});
                left=start;
                right=end;
            }
        }
        output.push_back({left,right});
        return output;
    }
};