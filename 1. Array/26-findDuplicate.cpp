// Find the duplicate number
// given an array of size n + 1 containing numbers in range [1, n],
// there is only one duplicate number, find it
// you cannot modify the array and must use O(1) extra space (optimal constraint)
// example -> Input:  [1, 3, 4, 2, 2]
//            Output : 2

#include <bits/stdc++.h>
using namespace std;

// brute force - O(n^2)
// compare every element with every other element
int findDuplicate(vector<int> &nums)
{
    int n = nums.size();
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (nums[i] == nums[j])
                return nums[i];
        }
    }
    return -1;
}

// better approach (using hashing) - O(n)
// Use a set or frequency array to track visited numbers)
int findDuplicateBetter(vector<int> &nums)
{
    unordered_set<int> st;
    for (int num : nums)
    {
        if (st.find(num) != st.end())
            return num;
        st.insert(num);
    }
    return -1;
}

// optimal approach (floyd's cycle detection) - O(n)
// treat array like a linked list:
//      index -> nums[index]
// since one number repeats, a cycle forms
//      slow pointer (1 step)
//      fast pointer (2 steps)
// Floyd’s Tortoise & Hare Algorithm
int findDuplicateOptimal(vector<int> &nums)
{
    int slow = nums[0];
    int fast = nums[0];
    // phase1: detect cycle
    do
    {
        slow = nums[slow];
        fast = nums[nums[fast]];
    } while (slow != fast);
    // phase2: find entrance of cycle
    slow = nums[0];
    while (slow != fast)
    {
        slow = nums[slow];
        fast = nums[fast];
    }
    return slow;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    

    return 0;
}