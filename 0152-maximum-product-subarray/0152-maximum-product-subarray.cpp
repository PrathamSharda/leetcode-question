class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int prefix=1;
        int suFix=1;
        int maxProd=INT_MIN;
        for(int i=0;i<nums.size();i++)
        {
            prefix*=nums[i];
            suFix*=nums[nums.size()-1-i];

            maxProd=max(maxProd,max(prefix,suFix));
            if(prefix==0)prefix=1;
            if(suFix==0)suFix=1;
        }
        return maxProd;
    }
};