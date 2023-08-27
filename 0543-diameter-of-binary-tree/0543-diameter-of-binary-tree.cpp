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
    int largedis = INT_MIN;
    
    int fn(TreeNode* root){
        if (root == nullptr)    return 0;
        if (root->left == nullptr && root->right == nullptr)    return 0;
        int ldis = 0, rdis = 0;
        if (root->left != nullptr){
            ldis = fn(root->left);
        }
        if (root->right != nullptr){
            rdis = fn(root->right);
        }
        int dis = ldis+rdis+2;
        if (root->left == nullptr)  dis-=1;
        if (root->right == nullptr) dis-=1;
        if (dis > largedis) largedis = dis;
        return (ldis > rdis)? ldis+1 : rdis+1;
    }
    
    int diameterOfBinaryTree(TreeNode* root) {
        if (root == nullptr)    return 0;
        if (root->left == nullptr && root->right == nullptr)    return 0;
        int tmp = fn(root);
        return largedis;
        
    }
};