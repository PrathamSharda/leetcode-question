class Solution {
public:
    int maxArea(vector<int>& height) {
        int p1=0;
        int p2=height.size()-1;
        int maxVol=0;
        while(p1<p2)
        {
            maxVol=max(maxVol,min(height[p1],height[p2])*(p2-p1));

            if(height[p2]<height[p1])p2--;
            else{
                p1++;
            }

        }
        return maxVol;
    }
};