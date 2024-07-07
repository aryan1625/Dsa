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
    pair<TreeNode*,int> solve(TreeNode* root){
        if(!root)return {NULL,0};
        if(!root->left && !root->right)return {root,1};
        pair<TreeNode*,int> left = solve(root->left);
        pair<TreeNode*,int> right = solve(root->right);
        if(left.second==right.second){
            return {root,left.second+1};
        }
        else if(left.second>right.second){
            return {left.first,left.second+1};
        }
        return {right.first,right.second+1};
        
    }
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        pair<TreeNode*,int> ans = solve(root);
        return ans.first;
    }
};