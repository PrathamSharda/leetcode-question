class Solution {
public:
    long long maximumSumOfHeights(vector<int>& arr) {
        long long maxSum=0;
        for(int i=0;i<arr.size();i++)
        {
            long long area=0;
            int p1=i-1;
            int p2=i+1;
            int mini=arr[i];
            area+=arr[i];
            for(int j=p1;j>=0;j--)
            {
                mini=min(mini,arr[j]);
                area+=mini;
            }
            mini=arr[i];
            for(int j=p2;j<arr.size();j++)
            {
                mini=min(mini,arr[j]);
                area+=mini;
            }
            maxSum=max(maxSum,area);
        }
        return maxSum;
    }
};