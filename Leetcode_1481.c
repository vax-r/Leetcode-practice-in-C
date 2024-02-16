int cmpfunc(const void *a, const void *b) {
    return *((int *)a) - *((int *)b);
}


int findLeastNumOfUniqueInts(int* arr, int arrSize, int k){
    const int n = arrSize;
    qsort(arr, n, sizeof(int), cmpfunc);

    int freq[n];
    int freq_size = 0;

    int cur_num = arr[0];
    int count = 1;

    for (int i = 1; i < n; i++) {
        if (cur_num == arr[i]) {
            count += 1;
        } else {
            freq[freq_size++] = count;
            cur_num = arr[i];
            count = 1;
        }
    }
    freq[freq_size++] = count;
    
    qsort(freq, freq_size, sizeof(int), cmpfunc);

    int delete = 0;
    for (int i = 0 ; i < freq_size && k >= freq[i]; i++) {
        delete += 1;
        k -= freq[i];
    }

    return freq_size - delete;
}