class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int top=0;
        int bottom=matrix.size()-1;
        while(top<=bottom)
        {
            int mid=(top+bottom)/2;
            
            if(matrix[mid][0]==target)return true;
            else if(matrix[mid][0]>target)
            {
                bottom=mid-1;
            }
            else{
                top=mid+1;
            }
        }

        if(bottom<0)return false;
        if(matrix[bottom][0]>target)return false;
        int left=0;
        int right=matrix[0].size()-1;
        while(left<=right)
        {
            int mid=(right+left)/2;
            if(matrix[bottom][mid]==target)
            {
                return true;
            }else if(matrix[bottom][mid]<target)
            {
                left=mid+1;
            }else{
                right=mid-1;
            }
        }
        return false;
    }
};