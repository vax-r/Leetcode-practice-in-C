int countLaser(char *row) {
    int sum = 0;
    for (int i=0; i < strlen(row); i++)
        if (row[i] == '1')
            sum++;
    return sum;
}

int numberOfBeams(char** bank, int bankSize) {
    int ans = 0;
    int r1 = 0, r2 = 1;
    while (r2 < bankSize) {
        int laser1 = countLaser(bank[r1]);
        if (!laser1) {
            r1 += 1;
            r2 += 1;
            continue;
        }
        int laser2 = countLaser(bank[r2]);
        if (!(laser1 * laser2)) {
            r2 += 1;
            continue;
        }
        ans += laser1 * laser2;
        r1 = r2;
        r2 += 1;
    }

    return ans;
}