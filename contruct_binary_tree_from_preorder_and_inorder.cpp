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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if(preorder.size() == 0){
            return NULL;
        }
        return buildTreeHelper(preorder, 0, preorder.size()-1, inorder, 0, inorder.size()-1);
    }

    TreeNode* buildTreeHelper(vector<int> preorder, int preStart, int preEnd, vector<int> inorder, int inStart, int inEnd){
        if(preStart > preEnd || inStart > inEnd){
            return NULL;
        }
        int rootData = preorder[preStart];
        int rootIndex;
        for(rootIndex = inStart; rootIndex <= inEnd; rootIndex++){
            if(inorder[rootIndex] == rootData){
                break;
            }
        }

        // inorder calculation
        int inorderLeftStart, inorderLeftEnd, inorderRightStart, inorderRightEnd;
        inorderLeftStart = inStart;
        inorderLeftEnd = rootIndex-1;
        inorderRightStart = rootIndex+1;
        inorderRightEnd = inEnd;

        // preorder calculation
        int preLeftStart, preLeftEnd, preRightStart, preRightEnd;
        preLeftStart = preStart+1;
        preLeftEnd = rootIndex - inStart + preStart;
        preRightStart = preLeftEnd + 1;
        preRightEnd = preEnd;

        

        TreeNode* root = new TreeNode(rootData);
        TreeNode* leftSubTree = buildTreeHelper(preorder, preLeftStart, preLeftEnd, inorder, inorderLeftStart, inorderLeftEnd);
        TreeNode* rightSubTree = buildTreeHelper(preorder, preRightStart, preRightEnd, inorder, inorderRightStart, inorderRightEnd);
        root->left = leftSubTree;
        root->right = rightSubTree;
        return root;

    }
};