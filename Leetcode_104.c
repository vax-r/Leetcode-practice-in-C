/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int maxDepth(struct TreeNode* root){
    if (!root)
        return 0;
    
    int lh = maxDepth(root->left);
    int rh = maxDepth(root->right);
    return lh > rh ? lh + 1 : rh + 1;
}