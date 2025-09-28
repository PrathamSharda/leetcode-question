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

TreeNode* builder(vector<int>&inorder,vector<int>&postOrder,unordered_map<int,int>&mp,int &index,int left,int right )
{
   
    if(index<0||index>inorder.size()-1)return nullptr;
    if(left>right)return nullptr;
    int position=mp[postOrder[index]];
    if(position>right||position<left)return nullptr;
    TreeNode*newNode= new TreeNode(postOrder[index]);
    index--;
    newNode->right=builder(inorder,postOrder,mp,index,position+1,right);
    newNode->left=builder(inorder,postOrder,mp,index,left,position-1);
    return newNode;

}
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int index=postorder.size()-1;
        unordered_map<int,int>mp;
        for(int i=0;i<inorder.size();i++)
        {
            mp[inorder[i]]=i;
        }
        return builder(inorder,postorder,mp,index,0,postorder.size()-1);
    }
};