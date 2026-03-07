// Repeating and missing values
// given an array of size n with elements from 1 to n
// one number is repeated, one is missing
// find both
// example --> input: nums = [4, 3, 6, 2, 1, 1]
//             output: repeating = 1, missing = 5
// array should have 1...6, but 1 repeats and 5 is missing

#include <bits/stdc++.h>
using namespace std;

// brute force - O(n^2)
// for each number from 1 to n, check how many times it occurs in the array
// count > 1 --> repeating
// count 0 --> missing
pair<int, int> findRepeatingMissingBrute(vector<int> &nums)
{
    int n = nums.size();
    int repeating = -1, missing = -1;
    for (int i = 1; i <= n; i++)
    {
        int count = 0;
        for (int num : nums)
            if (num == i)
                count++;
        if (count == 0)
            missing = i;
        else if (count > 1)
            repeating = i;
    }
    return {repeating, missing};
}

// better approach - O(nlogn) due to sorting
// sort the array
// traverse, compare index+1 with current value:
// if nums[i] == nums[i+1] → repeating
// if nums[i+1] != nums[i]+1 → missing
pair<int, int> findRepeatingMissingBetter(vector<int> &nums)
{
    sort(nums.begin(), nums.end());
    int repeating = -1, missing = -1;
    for (int i = 0; i < nums.size() - 1; i++)
    {
        if (nums[i] == nums[i + 1])
            repeating = nums[i];
        else if (nums[i + 1] != nums[i] + 1)
            missing = nums[i] + 1;
    }
    // check last element
    if (nums.back() != nums.size())
        missing = nums.size();
    return {repeating, missing};
}

// optimal - O(n)
// use math formulas:
//  sum_expected = n*(n+1)/2
//  sum_square_expected = n*(n+1)*(2n+1)/6
//  compute actual sum_actual and sum_square_actual
//  let x = missing, y = repeating
//  solve system:
//      x - y = sum_expected - sum_actual
//      x^2 - y^2 = sum_square_expected - sum_square_actual → (x+y)*(x-y)
pair<int, int> findRepeatingMissingOptimal(vector<int> &nums)
{
    long n = nums.size();
    long sum_n = n * (n + 1) / 2;
    long sum_sq_n = n * (n + 1) * (2 * n + 1) / 6;

    long sum_arr = 0, sum_sq_arr = 0;
    for (int num : nums)
    {
        sum_arr += num;
        sum_sq_arr += (long)num * num;
    }

    long diff = sum_n - sum_arr;                    // --> x - y
    long sum_diff = (sum_sq_n - sum_sq_arr) / diff; // --> x + y

    long missing = (diff + sum_diff) / 2;
    long repeating = missing - diff;
    return {repeating, missing};
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    vector<int> nums = {4, 3, 6, 2, 1, 1};
    pair<int, int> ansBrute = findRepeatingMissingBrute(nums);
    pair<int, int> ansBetter = findRepeatingMissingBetter(nums);
    pair<int, int> ansOptimal = findRepeatingMissingOptimal(nums);
    cout << "Repeating and missing values (brute): \n"
         << "Repeating: " << ansBrute.first << "\n"
         << "Missing: " << ansBrute.second << "\n";
    cout << "Repeating and missing values (better): \n"
         << "Repeating: " << ansBetter.first << "\n"
         << "Missing: " << ansBetter.second << "\n";
    cout << "Repeating and missing values (optimal): \n"
         << "Repeating: " << ansOptimal.first << "\n"
         << "Missing: " << ansOptimal.second << "\n";
    return 0;
}