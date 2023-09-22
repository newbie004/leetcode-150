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
    bool isSymmetric(TreeNode* root) {
        if(root == NULL){
            return true;
        }
        return isSymmetricHelper(root->left, root->right);      
    }

    bool isSymmetricHelper(TreeNode* leftTree, TreeNode* rightTree){
        /*
        left and right both are null -- true
        left is null -- false
        right is null -- false
        */
        if(leftTree == NULL || rightTree == NULL){
            return leftTree == rightTree;
        }
        if(leftTree->val != rightTree->val){
            return false;
        }
        return isSymmetricHelper(leftTree->left, rightTree->right) && isSymmetricHelper(leftTree->right, rightTree->left);
    }
};