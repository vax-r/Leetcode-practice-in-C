int removeElement(int* nums, int numsSize, int val) {
    if (numsSize == 1 && nums[0] == val)
        return 0;
    else if (numsSize == 1 && nums[0] != val)
        return 1;
    int head = 0, tail = numsSize - 1;
    while (head < tail) {
        while (tail >= 0 && nums[tail] == val)
            tail--;
        while (head < numsSize && nums[head] != val)
            head++;
        if (head >= tail)
            break;
        int tmp = nums[head];
        nums[head] = nums[tail];
        nums[tail] = tmp;
    }
    return head;
}