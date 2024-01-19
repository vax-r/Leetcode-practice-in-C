#define INVALID 2000
bool uniqueOccurrences(int* arr, int arrSize) {
    int occur[1001] = {0};
    for (int i=0; i<arrSize; i++) {
        if (arr[i] == INVALID)
            continue;
        int count = 1;
        for (int j = i + 1; j < arrSize; j++) {
            if (arr[j] != INVALID && arr[j] == arr[i]) {
                count++;
                arr[j] = INVALID;
            }
        }
        if (occur[count])
            return false;
        occur[count] += 1;
        arr[i] = INVALID;
    }
    return true;
}