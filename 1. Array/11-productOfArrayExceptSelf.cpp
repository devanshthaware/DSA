// Product of array except self
// given an integer array nums[], return an array answer[] such that:
// anwser[i] is equal to the product of all the element of nums except nums[i]
// notes -> division not allowed
//          you must handle zeroes properly
//          target time = O(n), space = O(1) (ignoring output array)
// example -> input: [1, 2, 3, 4]
//            Output: [24, 12, 8, 6] (why? -> [2*3*4, 1*3*4, 1*2*3])

#include <bits/stdc++.h>
using namespace std;

// brute force - O(n^2)
// for each i, loop over all other elements and multiply
// for each index i, compute the product of all other elements except nums[i]
vector<int> productExceptSelfBrute(vector<int> &nums)
{
    int n = nums.size();
    vector<int> result(n);
    for (size_t i = 0; i < n; i++)
    {
        /* code */
        int prod = 1;
        for (size_t j = 0; j < n; j++)
        {
            /* code */
            if (i != j)
            {
                prod *= nums[j];
            }
        }
        result[i] = prod;
    }
    return result;
}

// Optimal approach - time->O(n), space->O(n)(3 array used)
// create -> prefix: product of element before index i
//           suffix: product of elements after index i
// multiply them: prefix[i] * suffix[i]
vector<int> productExceptSelfOptimal(vector<int> &nums)
{
    int n = nums.size();
    vector<int> prefix(n, 1), suffix(n - 1), result(n);
    for (size_t i = 0; i < n; i++)
    {
        /* code */
        prefix[i] = prefix[i - 1] * nums[i - 1];
    }
    for (int i = n - 2; i >= 0; i--) // always use a signed integer (int) for reverse loops because size_t is unsigned, unsigned numbers don’t go below zero
    {
        /* code */
        suffix[i] = suffix[i + 1] * nums[i - 1];
    }
    for (size_t i = 0; i < n; i++)
    {
        /* code */
        result[i] = prefix[i] * suffix[i];
    }
    return result;
}

// Further optimization
// reduce space from O(n) to O(1)
// use the result[] array itself to store prefix products
// on the second pass (from the end), multiply suffix product directly into result[]
vector<int> productExceptSelfFurtherOpti (vector<int>& nums) {
    int n = nums.size();
    vector<int> result(n, 1);
    int prefix = 1;
    for (size_t i = 0; i < n; i++)
    {
        /* code */
        result[i] = prefix;
        prefix *= nums[i];
    }
    int suffix = 1;
    for (int i = n - 1; i >= 0; i--) // always use a signed integer (int) for reverse loops because size_t is unsigned, unsigned numbers don’t go below zero
    {
        /* code */
        result[i] *= suffix;
        suffix *= nums[i];
    }
    return result;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    vector<int> nums = {1, 2, 3, 4};
    vector<int> resultBrute = productExceptSelfBrute(nums);
    cout << "Product of array except self (brute): ";
    for (int x : resultBrute)
    {
        cout << x << " ";
    }
    cout << "\n";
    vector<int> resultOpti = productExceptSelfFurtherOpti(nums);
    cout << "Product of array except self (brute): ";
    for (int x : resultOpti)
    {
        cout << x << " ";
    }
    cout << "\n";
    return 0;
}