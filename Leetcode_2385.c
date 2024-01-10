#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

#define MAX(a,b) (((a)>(b))?(a):(b))

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
 };

bool findStart(struct TreeNode *root, int start) {
    if (!root)
        return false;
    if (root->val == start) {
        root->val = 0;
        return true;
    }
    if (findStart(root->left, start)) {
        root->val = root->left->val - 1;
        return true;
    }
    if (findStart(root->right, start)) {
        root->val = root->right->val - 1;
        return true;
    }
    return false;
}

/* Amount of time to infect the binary tree rooted at root */
int infection(struct TreeNode *root, int *ans) {
    if (!root)
        return 0;
    
    int tmp;

    if (root->val < 0) {
        tmp = -(root->val);
        if (root->left && root->left->val <= 0) {
            infection(root->left, ans);
            tmp += infection(root->right, ans);
        }
        if (root->right && root->right->val <= 0) {
            infection(root->right, ans);
            tmp += infection(root->left, ans);
        }
        *ans = MAX(*ans, tmp);
        return tmp;
    }

    tmp = MAX(infection(root->left, ans), infection(root->right, ans));
    if (root->val > 0)
        tmp += 1;
    *ans = MAX(*ans, tmp);
    return tmp;
}


int amountOfTime(struct TreeNode* root, int start) {
    findStart(root, start);
    int ans = 0;
    infection(root, &ans);
    return ans;
}

int main() {

    struct TreeNode nodes[5];
    for (int i=0; i<5; i++) {
        nodes[i].val = i+1;
        node[i].left = NULL;
        node[i].right = NULL;
    }
    
    nodes[0].left = &nodes[1];
    nodes[1].left = &nodes[2];
    nodes[2].left = &nodes[3];
    nodes[3].left = &nodes[4];

    int ans = amountOfTime(&nodes[0], 2);
    printf("ans : %d\n", ans);

    return 0;
}