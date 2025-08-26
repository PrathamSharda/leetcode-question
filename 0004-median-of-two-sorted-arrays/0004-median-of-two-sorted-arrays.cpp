class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int p1=0;
        int p2=0;
        vector<int>ans;
        if(nums1.size()==1&&nums2.size()==0)
        {
            return (double) nums1[0];
        }
        if(nums2.size()==1&&nums1.size()==0)
        {
            return (double) nums2[0];
        }

        while(p1<nums1.size()&&p2<nums2.size())
        {
            if(nums1[p1]<nums2[p2])
            {
                ans.push_back(nums1[p1]);
                p1++;
            }else{
                ans.push_back(nums2[p2]);
                p2++;
            }
        }

        while(p1<nums1.size())
        {
            ans.push_back(nums1[p1]);
            p1++;
        }
        while(p2<nums2.size())
        {
            ans.push_back(nums2[p2]);
            p2++;
        }
        double avg;
        if(ans.size()%2==0)
        {
            p1=ans.size()/2;
            p2=ans.size()/2-1;
            avg=double (ans[p1]+ans[p2])/2;
        }else{
             p1=ans.size()/2;
             avg=ans[p1];
        }
        return avg;

        
    }
};