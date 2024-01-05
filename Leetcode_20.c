void push(char *stack, char c, int *top) {
    stack[*top] = c;
    *top += 1;
}

void pop(char *stack, int *top) {
    *top -= 1;
    stack[*top] = '\0';
}

bool isValid(char* s) {
    char *stack = calloc(10000 + 1, sizeof(char));
    int top = 0;

    for (int i=0; i<strlen(s); i++) {
        switch (s[i]) {
            case '(':
            case '[':
            case '{':
                push(stack, s[i], &top);
                break;
            case ')':
                if (top && stack[top-1] == '(')
                    pop(stack, &top);
                else
                    return false;
                break;
            case ']':
                if (top && stack[top-1] == '[')
                    pop(stack, &top);
                else
                    return false;
                break;
            case '}':
                if(top && stack[top-1] == '{')
                    pop(stack, &top);
                else
                    return false;
                break;
            default:
                break;
        }
    }
    return top ? false : true;
}