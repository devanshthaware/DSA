// Maximum subarray sum --> Find the subarray that has the largest possible sum among all subarrays...

#include <bits/stdc++.h>
using namespace std;

// Brute force (works correctly but time complexity is O(N^3))
template <size_t N>
size_t maxSubarraySum (int (&arr)[N]){
    int maxSum = INT32_MIN;
    for (size_t i = 0; i < N; i++) // <-- picks starting index
    {
        /* code */
        for (size_t j = i; j < N; j++) // <-- picks ending index
        {
            /* code */
            int sum = 0;
            for (size_t k = i; k <= j; k++) // <-- calculate sum of subarray arr[i...j]
            {
                /* code */
                sum += arr[k];
                maxSum = max(maxSum, sum); // <-- update maxSum if needed
            }
            
        }
        
    }
    return maxSum;
}

// Small Optimization --> reduce it to O(N^2) by accumulating instead of recalculating sum each time...
template <size_t N>
int maxSubarraySumBetter(int (&arr)[N])
{
    int maxSum = INT_MIN;

    for (size_t i = 0; i < N; i++)
    {
        int sum = 0;
        for (size_t j = i; j < N; j++)
        {
            sum += arr[j];
            maxSum = std::max(maxSum, sum);
        }
    }

    return maxSum;
}

// Kadane's algorithm - Optimal solution (O(N))
// instead of checking allsubarrays, intelligently expand or restatrt subarrays based on sum...
template <size_t N>
int maxSubarraySumOptimal (int (&arr)[N]){
    int maxSum = INT32_MIN;
    int currSum = 0;
    for (size_t i = 0; i < N; i++)
    {
        /* code */
        currSum += arr[i]; // <-- add current element to the currSum
        maxSum = max(maxSum, currSum); // <-- update maxSum if currSum is larger
        if (currSum < 0) // <-- if currSum becmes -ve, reset it to 0
            currSum = 0;
    }
    return maxSum;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int arr[] = {1, -2, 3, 4, -1, -2};
    cout << "Maximum Subarray sum (brute force): " << maxSubarraySum(arr) << "\n"; // 7
    cout << "Maximum Subarray sum (better): " << maxSubarraySumBetter(arr) << "\n"; // 7
    cout << "Maximum Subarray sum (optimal): " << maxSubarraySumOptimal(arr) << "\n"; // 7

    return 0;
}