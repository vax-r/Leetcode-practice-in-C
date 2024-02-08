typedef struct Node {
    int id;
    struct Node *next;
};


struct Node *append_adjlist (struct Node *list, int new_id) {
    struct Node *new_node = calloc(1, sizeof(struct Node));
    new_node->id = new_id;
    new_node->next = NULL;

    if (!list) {
        list = new_node;
        return list;
    }

    struct Node *ite = list;
    for (; ite->next; ite = ite->next);
    ite->next = new_node;
    return list;
}

void graph_free(struct Node **graph, int n) {
    for (int i=0; i<n; i++)
        free(graph[i]);
    free(graph);
}

int* findOrder(int numCourses, int** prerequisites, int prerequisitesSize, int* prerequisitesColSize, int* returnSize) {
    struct Node **graph = calloc(numCourses, sizeof(struct Node *));
    int *in_deg = calloc(numCourses, sizeof(int));

    for (int i=0; i<prerequisitesSize; i++) {
        graph[prerequisites[i][1]] = append_adjlist(graph[prerequisites[i][1]], prerequisites[i][0]);
        in_deg[prerequisites[i][0]] += 1;
    }

    bool cyclic = false;
    int *ans = calloc(numCourses, sizeof(int));
    for (int i=0; i<numCourses; i++) {
        int s = 0;
        while (s < numCourses && in_deg[s] != 0)
            s += 1;
        
        if (s == numCourses) {
            cyclic = true;
            break;
        }

        in_deg[s] = -1;
        ans[i] = s;

        for (struct Node *ite = graph[s]; ite; ite = ite->next)
            in_deg[ite->id] -= 1;
    }

    if (cyclic) {
        *returnSize = 0;
        graph_free(graph, numCourses);
        free(in_deg);
        return (int *) NULL;
    }

    graph_free(graph, numCourses);
    free(in_deg);
    *returnSize = numCourses;
    return ans;
}