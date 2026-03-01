// Buy and sell stock problem 

#include <bits/stdc++.h>
using namespace std;

// Case 1 --> (single transaction)
// given an array prices[], where prices[i] is the stock price on day i.
// goal: buy at one day and sell at a later day to get maximum profit.

// brute force O(n^2)
int maxProfit(vector<int> &prices)
{
    int n = prices.size();
    int best = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            best = max(best, prices[j] - prices[i]);
        }
    }
    return best;
}

// Optimal - O(n)
int maxProfitOptimal(vector<int> &prices)
{
    int minPrice = INT32_MAX;
    int bestProfit = 0;
    for (int price : prices)
    {
        minPrice = min(minPrice, price);
        bestProfit = max(bestProfit, price - minPrice);
    }
    return bestProfit;
}

// Case 2 --> Multiple(unlimited) transaction
// Every upward price movement is profit.
// If price[i] > price[i-1], just take the difference.
// don’t need to find valleys and peaks explicitly. Just accumulate every positive slope.
int maxProfitUnlimited(vector<int> &prices)
{
    int profit = 0;

    for (int i = 1; i < prices.size(); i++)
    {
        if (prices[i] > prices[i - 1])
            profit += prices[i] - prices[i - 1];
    }

    return profit;
}
// Case 3 --> With Cooldown (1 day cooldown after selling)
// After you sell, you must wait 1 day before buying again.
int maxProfitCooldown(vector<int> &prices)
{
    if (prices.empty())
        return 0;

    int hold = -prices[0];
    int sold = 0;
    int rest = 0;

    for (int i = 1; i < prices.size(); i++)
    {
        int prevSold = sold;

        sold = hold + prices[i];
        hold = max(hold, rest - prices[i]);
        rest = max(rest, prevSold);
    }

    return max(sold, rest);
}
// Case 4 --> At Most K Transactions - O(nK)
// dp[k][i] = max profit using at most k transactions up to day i.
int maxProfitKTransactions(int K, vector<int> &prices)
{
    int n = prices.size();
    if (n == 0)
        return 0;

    if (K >= n / 2)
    {
        int profit = 0;
        for (int i = 1; i < n; i++)
            if (prices[i] > prices[i - 1])
                profit += prices[i] - prices[i - 1];
        return profit;
    }

    vector<int> buy(K + 1, INT_MIN);
    vector<int> sell(K + 1, 0);

    for (int price : prices)
    {
        for (int k = 1; k <= K; k++)
        {
            buy[k] = max(buy[k], sell[k - 1] - price);
            sell[k] = max(sell[k], buy[k] + price);
        }
    }

    return sell[K];
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    return 0;
}