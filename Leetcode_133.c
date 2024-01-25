struct Node *dfs(struct Node *s, bool visited[], struct Node *saved[]) {
    if (visited[s->val])
        return saved[s->val];
    struct Node *new_node = calloc(1, sizeof(struct Node));
    new_node->val = s->val;

    visited[s->val] = true;
    saved[s->val] = new_node;

    new_node->numNeighbors = s->numNeighbors;
    new_node->neighbors = calloc(s->numNeighbors, sizeof(struct Node*));

    for (int i=0; i < s->numNeighbors; i++)
        new_node->neighbors[i] = dfs(s->neighbors[i], visited, saved);
    return new_node;
}

struct Node *cloneGraph(struct Node *s) {
	if (!s)
        return NULL;
    bool visited[101] = {false};
    struct Node *saved[101];
    return dfs(s, visited, saved);
}