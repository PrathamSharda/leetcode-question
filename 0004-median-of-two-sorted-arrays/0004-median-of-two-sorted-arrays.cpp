class Solution {
public:

    // double median(vector<int>&a,vector<int>&b)
    // {
        
    // }
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
         if(nums1.size() > nums2.size()) return findMedianSortedArrays(nums2, nums1);
        int l=0;
        int r=nums1.size();

       int total=nums1.size()+nums2.size();
       int n1=nums1.size();
       int n2=nums2.size();
       if(n1==1&&n2==0)
       {
        return nums1[0];
       }
       if(n1==0&&n2==1)
       {
        return nums2[0];
       }
       while(l<=r)
       {
            int cut1 = (l + r) / 2;
            int cut2 = (total + 1) / 2 - cut1;

            int l1 = (cut1 == 0 ? INT_MIN : nums1[cut1 - 1]);
            int r1 = (cut1 == n1 ? INT_MAX : nums1[cut1]);
            int l2 = (cut2 == 0 ? INT_MIN : nums2[cut2 - 1]);
            int r2 = (cut2 == n2 ? INT_MAX : nums2[cut2]);
            
           if(l1 <= r2 && l2 <= r1) {
                if(total % 2 == 0)
                    return (max(l1, l2) + min(r1, r2)) / 2.0;
                else
                    return max(l1, l2);
            }
            else if(l1 > r2) {
                r = cut1 - 1;
            } else {
                l = cut1 + 1;
            }

       }
      
       return 0;
    }
};