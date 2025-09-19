class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int left=0;
        int right=nums.size()-1;
        int maxiNum=INT_MIN;
        int maxIndex=-1;
        while(left<=right)
        {
            int mid=(left+right)/2;
            int preL=mid-1>=0?mid-1:mid;
            int preR=mid+1<=nums.size()-1?mid+1:mid;

            if(nums[mid]>=nums[preL]&&nums[mid]>=nums[preR])return mid;
            if(nums[mid]>nums[preL])
            {

                left=mid+1;
            }
            else
            {
                right=mid-1;
            }
        }
        return left+1;

    }
};