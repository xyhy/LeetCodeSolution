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
    int mini = INT_MAX;
    int preval = -1;
    void fn(TreeNode* root){
        if (root == nullptr) return;
        
        if(root->left != nullptr){
            fn(root->left);
        }
        
        if (preval != -1){
            if(mini > root->val-preval) mini = root->val-preval;
        }
        preval = root->val;
        
        if(root->right != nullptr){
            fn(root->right);
        }

    }
        
        
    int getMinimumDifference(TreeNode* root) {
        fn(root);
        return mini;
    }
};