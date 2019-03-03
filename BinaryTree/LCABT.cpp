// Tested on https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == NULL)
            return root;
        if(root == p || root == q)
            return root;
        TreeNode* leftChild = lowestCommonAncestor(root->left,p,q);
        TreeNode* rightChild = lowestCommonAncestor(root->right,p,q);
        if(leftChild!=NULL && rightChild != NULL)
            return root;
        if(leftChild != NULL)
            return leftChild;
        return rightChild;
    }
};
