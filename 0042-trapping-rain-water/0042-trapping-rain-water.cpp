class Solution {
public:
    int trap(vector<int>& height) {
        
        vector<int>suffix(height.size(),0);
        vector<int>prefix(height.size(),0);
        prefix[0]=height[0];
        for(int i=1;i<prefix.size();i++)
        {
            prefix[i]=max(height[i],prefix[i-1]);
        }
        int n=height.size();
        suffix[n-1]=height[n-1];
        for(int i=prefix.size()-2;i>=0;i--)
        {
            suffix[i]=max(height[i],suffix[i+1]);
        }
        int total=0;
        for(int i=0;i<height.size();i++)
        {
            int left=prefix[i];
            int right=suffix[i];
            if(height[i]<left&&height[i]<right)
            {
                total+=min(right,left)-height[i];
            }
        }
        return total;

    }
};