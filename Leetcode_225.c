


typedef struct {
    int *queue_1,*queue_2;
    int top1;
    int capacity;
} MyStack;


MyStack* myStackCreate() {
    MyStack* stack=(MyStack*)malloc(sizeof(MyStack));
    stack->capacity=100;
    stack->top1=-1;
    stack->queue_1=(int*)malloc(sizeof(int)*stack->capacity);
    stack->queue_2=(int*)malloc(sizeof(int)*stack->capacity);
    return stack;
}

void myStackPush(MyStack* obj, int x) {
    if(obj->top1+1==obj->capacity)
        return;//stack is fulled
    int i;
    for(i=0;i<=obj->top1;i++){
        obj->queue_2[i]=obj->queue_1[i];
    }
    obj->queue_1[0]=x;
    for(i=0;i<=obj->top1;i++){
        obj->queue_1[i+1]=obj->queue_2[i];
    }
    obj->top1+=1;
}

int myStackPop(MyStack* obj) {
    if(obj->top1==-1)
        return -1;//stack is empty
    int item=obj->queue_1[0];
    int i;
    for(i=0;i<obj->top1;i++)
        obj->queue_1[i]=obj->queue_1[i+1];
    obj->top1-=1;
    return item;
}

int myStackTop(MyStack* obj) {
    if(obj->top1==-1)
        return -1;
    return obj->queue_1[0];
}

bool myStackEmpty(MyStack* obj) {
    if(obj->top1==-1)
        return true;
    return false;
}

void myStackFree(MyStack* obj) {
    obj->top1=-1;
    free(obj->queue_1);
    free(obj->queue_2);
    free(obj);
}

/**
 * Your MyStack struct will be instantiated and called as such:
 * MyStack* obj = myStackCreate();
 * myStackPush(obj, x);
 
 * int param_2 = myStackPop(obj);
 
 * int param_3 = myStackTop(obj);
 
 * bool param_4 = myStackEmpty(obj);
 
 * myStackFree(obj);
*/