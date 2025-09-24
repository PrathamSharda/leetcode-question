class Solution {
public:

    int jump(vector<int>& nums) {
        int jumps=0;
        int left=0;
        int right=0;
        while(right<nums.size()-1)
        {
            int maxIndex=0;
            for(int i=left;i<=right;i++)
            {
                maxIndex=max(maxIndex,i+nums[i]);
            }
            jumps++;
            left=right+1;
            right=maxIndex;

        }
        return jumps;
    
    }
};