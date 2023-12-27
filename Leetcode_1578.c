int removeTime(int *neededTime, int left, int right) {
    if (left == right)
        return 0;
    int max = -1, sum = 0;
    for (int i=left; i<right; i++) {
        sum += neededTime[i];
        if (max < neededTime[i])
            max = neededTime[i];
    }
    return sum - max;
}

int minCost(char * colors, int* neededTime, int neededTimeSize){
    int time = 0, local_max = -1, left = 0, right = 0;
    while (right < neededTimeSize) {
        while (colors[left] == colors[right])
            right++;
        time += removeTime(neededTime, left, right);
        left = right;
    }
    return time;
}