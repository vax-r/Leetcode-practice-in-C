/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

void inorder(struct TreeNode *root, int *buffer, int *size) {
    if (!root)
        return;
    inorder(root->left, buffer, size);
    buffer[*size] = root->val;
    *size += 1;
    inorder(root->right, buffer, size);
}


int* inorderTraversal(struct TreeNode* root, int* returnSize) {
    int *output = calloc(100, sizeof(int));
    *returnSize = 0;
    inorder(root, output, returnSize);
    return output;
}