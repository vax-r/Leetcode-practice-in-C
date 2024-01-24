#define RANGE 10

void dfs (struct TreeNode *cur, int *table, int *ans) {
    if (!cur->left && !cur->right) {
        table[cur->val]++;
        int odd_count = 0;
        for (int i=1; i<RANGE; i++)
            if (table[i] % 2)
                odd_count++;
        if (odd_count <= 1)
            *ans += 1;
        table[cur->val]--;
        return;
    }

    table[cur->val]++;
    if (cur->left)
        dfs(cur->left, table, ans);
    if (cur->right)
        dfs(cur->right, table, ans);
    table[cur->val]--;
}

int pseudoPalindromicPaths (struct TreeNode* root) {
    int ans = 0;
    int *table = calloc(RANGE, sizeof(int));

    dfs(root, table, &ans);

    free(table);
    return ans;
}