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
    void dfs(TreeNode*root,unordered_map<int,int>&mp)
    {
        if(root==nullptr)
        {
            return ;
        }
        mp[root->val]++;
        dfs(root->left,mp);
        dfs(root->right,mp);
    }
    bool findTarget(TreeNode* root, int k) 
    {
        unordered_map<int,int>mp;

        dfs(root,mp);

        for(auto it:mp)
        {
            int num=k-it.first;
            if(mp.find(num)!=mp.end())
            {
                if(it.first!=num)
                return true;
                else{
                    if(it.second-1!=0)return true;
                }
            }
        }
        return false;
    }
};