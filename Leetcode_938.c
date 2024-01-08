/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

int inorderSum(struct TreeNode *root, int low, int high) {
    if (!root)
        return 0;
    int tmp = root->val >= low && root->val <= high ? root->val : 0;
    return inorderSum(root->left, low, high) + tmp + inorderSum(root->right, low, high);
}

int rangeSumBST(struct TreeNode* root, int low, int high) {
    return inorderSum(root, low, high);
}