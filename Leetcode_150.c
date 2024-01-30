int evalRPN(char** tokens, int tokensSize) {
    int *stack = calloc(10000, sizeof(int));
    int top = 0, ans;

    for (int i=0; i<tokensSize; i++) {
        if (!strcmp(tokens[i], "+")) {
            int tmp = stack[top - 2] + stack[top - 1];
            top -= 2;
            stack[top] = tmp;
            top++;
        }
        else if (!strcmp(tokens[i], "-")) {
            int tmp = stack[top - 2] - stack[top - 1];
            top -= 2;
            stack[top] = tmp;
            top++;
        }
        else if (!strcmp(tokens[i], "*")) {
            int tmp = stack[top - 2] * stack[top - 1];
            top -= 2;
            stack[top] = tmp;
            top++;
        }
        else if (!strcmp(tokens[i], "/")) {
            int tmp = stack[top - 2] / stack[top - 1];
            top -= 2;
            stack[top] = tmp;
            top++;
        }
        else {
            int tmp = atoi(tokens[i]);
            stack[top] = tmp;
            top++;
        }
    }

    ans = stack[top - 1];

    free(stack);
    return ans;
}