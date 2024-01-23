int hIndex(int* citations, int citationsSize) {
    int h = 0;
    while (true) {
        int count = 0;
        for (int i=0; i<citationsSize; i++)
            if (citations[i] >= h)
                count++;
        if (count < h)
            break;
        h++;
    }
    return h - 1;
}