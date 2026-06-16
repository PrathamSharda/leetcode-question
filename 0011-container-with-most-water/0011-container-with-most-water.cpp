class Solution {
public:
    int maxArea(vector<int>& arr) {
        int left=0;
        int right=arr.size()-1;
        int maxWater=0;
        while(left<right)
        {
            maxWater=max(maxWater,min(arr[left],arr[right])*(right-left));
            if(arr[left]<arr[right])left++;
            else right--;
        }
        return maxWater;
    }
};