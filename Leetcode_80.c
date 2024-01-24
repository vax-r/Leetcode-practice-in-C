int removeDuplicates(int* nums, int numsSize) {
    int k = 1;
    bool exist = false;
    for (int i = 1; i < numsSize; i++) {
        if (nums[i] != nums[i - 1]) {
            nums[k] = nums[i];
            exist = false;
            k++;
        }
        else if (nums[i] == nums[i - 1] && !exist) {
            nums[k] = nums[i];
            exist = true;
            k++;
        }
    }
    return k;
}