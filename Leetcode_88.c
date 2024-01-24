void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n) {
    int *result = calloc(nums1Size, sizeof(int));
    int i = 0, j = 0, k = 0;
    while (i < m && j < n) {
        if (nums1[i] <= nums2[j]) {
            result[k] = nums1[i];
            i += 1;
            k += 1;
        } else {
            result[k] = nums2[j];
            j += 1;
            k += 1;
        }
    }
    while (i < m)
        result[k++] = nums1[i++];
    while (j < n)
        result[k++] = nums2[j++];
    memcpy(nums1, result, sizeof(int) * nums1Size);
    free(result);
}