// Allocate book problem
// given an array arr[] where arr[i] denotes the number of pages in the i-th book and an integer m (number of students)
// allocate books to m student such that:
//      each student gets atleast one book
//      each book is assigned to only one student
//      books are assigned in contiguous order
// minimize the maximum number of pages assigned to a student
// example --> input: arr = [12, 34, 67, 90], m = 2
//             output: 113
// explanation: allocation 12, 34, 67, 90
//              max pages = max(12 + 34 + 67, 90) = 113, which is the minimum possible

#include <bits/stdc++.h>
using namespace std;

// approach:
// binary search on answer space
//      minimum pages possible = max(arr)
//      maximum pages = sum(arr)
//      binary search in this range and check if its possible to allocate books so that no student has more than mid pages
// how to check if a mid is valid
//      isValid(mild) logic:
//          simulate allocation:
//              start asigning books to the first student
//              if the pages assigned exceed mid, move to the next student
//              if number of students required > m, then mid is invalid
// time complexity: O(Nlog(S)) where N -> number of books, S -> sum of pages - max page value
bool isValid(const vector<int> &books, int m, int maxPages)
{
    int studentCount = 1;
    int pagesSum = 0;
    for (int pages : books)
    {
        // If a single book has more pages than maxPages
        if (pages > maxPages)
            return false;
        // If adding this book exceeds maxPages
        if (pagesSum + pages > maxPages)
        {
            studentCount++;
            pagesSum = pages;
            if (studentCount > m)
                return false;
        }
        else
        {
            pagesSum += pages;
        }
    }
    return true;
}
int allocateBooks(vector<int> &books, int m)
{
    int n = books.size();
    if (m > n)
        return -1;
    int low = *max_element(books.begin(), books.end());
    int high = accumulate(books.begin(), books.end(), 0);
    int result = -1;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (isValid(books, m, mid))
        {
            result = mid;
            high = mid - 1; // try smaller max
        }
        else
        {
            low = mid + 1; // increase max
        }
    }
    return result;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    vector<int> books = {12, 34, 67, 90};
    int students = 2;
    cout << allocateBooks(books, students);
    return 0;
}