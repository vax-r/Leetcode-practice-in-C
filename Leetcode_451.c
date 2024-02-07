#define OFFSET 48
#define SIZE 75

typedef struct char_freq {
    int cid;
    int freq;
};

void init (struct char_freq *arr) {
    for (int i=0; i<SIZE; i++) {
        arr[i].cid = OFFSET + i;
        arr[i].freq = 0;
    }
}

int cmpfunc (const void *a, const void *b) {
    struct char_freq *char_a = (struct char_freq *) a;
    struct char_freq *char_b = (struct char_freq *) b;
    return (char_b->freq - char_a->freq);
}

char* frequencySort(char* s) {
    struct char_freq arr[SIZE];
    init(arr);

    for (int i=0; i<strlen(s); i++) {
        arr[s[i] - OFFSET].freq += 1;
    }

    qsort(arr, SIZE, sizeof(struct char_freq), cmpfunc);

    char *sorted_s = calloc(strlen(s) + 1, sizeof(char));
    
    int k=0;
    for (int i=0; i<SIZE; i++) {
        for (int j=0; j<arr[i].freq; j++) {
            sorted_s[k] = arr[i].cid;
            k += 1;
        }
    }

    return sorted_s;
}