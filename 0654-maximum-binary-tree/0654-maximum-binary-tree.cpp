/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* elementMaker(vector<int>&nums,int left,int right)
    {
        if(left>=right)return nullptr;
        int maxEle=-1;
        int index=-1;
        for(int i=left;i<right;i++){
            if(maxEle<nums[i])
            {
                maxEle=nums[i];
                index=i;
            }
        }
        if(maxEle==-1)return nullptr;

        TreeNode* root=new TreeNode(maxEle);

        root->left=elementMaker(nums,left,index);
        root->right=elementMaker(nums,index+1,right);
        return root;

    }
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
       return elementMaker(nums,0,nums.size());
    }
};