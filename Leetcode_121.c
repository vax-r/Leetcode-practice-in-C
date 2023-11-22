int maxProfit(int* prices, int pricesSize) {
    int lowest_day = 0, profit = 0;
    for (int i = 1; i < pricesSize; i++) {
        if (prices[i] - prices[lowest_day] > profit)
            profit = prices[i] - prices[lowest_day];
        if (prices[i] < prices[lowest_day])
            lowest_day = i;
    }
    return profit;
}