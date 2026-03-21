// Online Stock Span (Design)
// design a class stock spanner  that collects daily stock price for the current day
// span definition ->
//  the span of today's price is:
//      the number of consecutive days (including today) where previous price <= today's price
// example ->   input:  next(100)
//                      next(80)
//                      next(60)
//                      next(70)
//                      next(60)
//                      next(75)
//                      next(85)
//              output: 1
//                      1
//                      1
//                      2
//                      1
//                      4
//                      6
// why? ->  day 1: 100 -> span = 1
//          day 2: 80
//              100 > 80 -> stop
//              span = 1
//          day 4: 70
//              60 <= 70 -> count
//              80 > 70 -> stop
//              span = 2
//          day 7: 85
//              75 <= 85
//              60 <= 85
//              70 <= 85
//              60 <= 85
//              80 <= 85
//              100 > 85 -> stop
//              span = 6

#include <bits/stdc++.h>
using namespace std;

// brute force -> O(n^2)
// for each new price 
//  go backwards
//  count how many previous price are <= current price
//  stop when you find a greater price
class StockSpanner {
private:
    vector<int> prices;
public:
    int next (int price) {
        prices.push_back(price);
        int span = 1;
        for (int i = prices.size() - 2; i >= 0; i--) {
            if (prices[i] <= price)
                span++;
            else
                break;
        }
        return span;
    }
};

// better approach -> 
// instead of checking one day at time, store
//      (price, index)
// then jump directly to previous greater element
// this avoids every single day sequentially
// complexity -> still O(n^2) but slightly optimized in practice, space: O(n)
class StockSpannerBetter {
private:
    vector<int> prices;
public:
    int nextBetter (int price) {
        prices.push_back(price);
        int i = prices.size() - 1;
        int span = 1;
        while (i > 0 && prices[i - 1] <= price) {
            span++;
            i--;
        }
        return span;
    }
};

// optimal approach -> monotonic stack
// complexity: time: O(n), space: O(n)
// use a monotonic decreasing stack
// store: (price, span)
// instead of counting day by day, ->
//  pop smaller price
//  add their span directly
// this compresses history
// algorithm ->
// span = 1
// while stack not empty AND top.price <= current:
//      span += top.span
//      pop
// push(current price, span)
// return span
class StockSpannerOptimal {
private:
    stack<pair<int, int>> st; // pair<price, span>
public:
    StockSpannerOptimal() {}
    int next (int price) {
        int span = 1;
        while (!st.empty() && st.top().first <= price) {
            span += st.top().second;
            st.pop();
        }
        st.push({price, span});
        return span;
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    return 0;
}