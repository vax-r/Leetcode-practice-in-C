typedef struct {
    int s1[101], s1_bottom, s1_top, s1_cap;
    int s2[101], s2_bottom, s2_top, s2_cap;    
} MyQueue;


MyQueue* myQueueCreate() {
    MyQueue *q = calloc(1, sizeof(MyQueue));
    q->s1_bottom = 0;
    q->s1_top = 0;
    q->s1_cap = 101;
    q->s2_bottom = 0;
    q->s2_top = 0;
    q->s2_cap = 101;
    return q;
}

void myQueuePush(MyQueue* obj, int x) {
    /* s1 is fulled */
    if ((obj->s1_top + 1 == obj->s1_cap) || (obj->s2_top + 1 == obj->s2_cap))
        return;

    /* When elements are still stored in s2 */
    if ((obj->s1_top == obj->s1_bottom)) {
        while (obj->s2_top > obj->s2_bottom) {
            obj->s2_top -= 1;
            obj->s1[obj->s1_top] = obj->s2[obj->s2_top];
            obj->s1_top += 1;
        }
    }

    obj->s1[obj->s1_top] = x;
    obj->s1_top += 1;
}

int myQueuePop(MyQueue* obj) {
    /* If s1 isn't empty, move all elements from s1 to s2 */
    while (obj->s1_top > obj->s1_bottom) {
        obj->s1_top -= 1;
        obj->s2[obj->s2_top] = obj->s1[obj->s1_top];
        obj->s2_top += 1;
    }

    int tmp = obj->s2[obj->s2_top - 1];
    obj->s2_top -= 1;
    return tmp;
}

int myQueuePeek(MyQueue* obj) {
    int ans;
    if (obj->s2_top == obj->s2_bottom)
        ans = obj->s1[obj->s1_bottom];
    
    if (obj->s1_top == obj->s1_bottom)
        ans = obj->s2[obj->s2_top - 1];
    
    return ans;
}

bool myQueueEmpty(MyQueue* obj) {
    if (obj->s1_top == obj->s1_bottom && obj->s2_top == obj->s2_bottom)
        return true;
    return false;
}

void myQueueFree(MyQueue* obj) {
    free(obj);
}