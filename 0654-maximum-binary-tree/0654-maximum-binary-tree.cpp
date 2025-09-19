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
 
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
       stack<TreeNode*>st;
       for(int i=0;i<nums.size();i++)
       {
            TreeNode* NewNode=new TreeNode(nums[i]);
            TreeNode*prev=nullptr;
            int flag=0;
            while(!st.empty()&&st.top()->val<nums[i])
            {
                flag=1;
                TreeNode*curr=st.top();
                curr->right=prev;
                prev=curr;
                st.pop();
            }
            if(flag)
            {
                NewNode->left=prev;
            }
            st.push(NewNode);
       }
        TreeNode*prev=nullptr;
         while(!st.empty())
            {
    
                TreeNode*curr=st.top();
                curr->right=prev;
                prev=curr;
                st.pop();
            }
            return prev;


    }
};