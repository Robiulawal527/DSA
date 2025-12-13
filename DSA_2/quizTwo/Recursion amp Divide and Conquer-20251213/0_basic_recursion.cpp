/**
 * @file 0_basic_recursion.cpp
 * @author S-M-J-I
 * @brief Recursion examples
 * @version 0.1
 * @date 2025-11-22
 *
 * @copyright Copyright (c) 2025
 *
 */

/**
 * how to think recursively?
 * step 0: the hardest part is trusting that if your function works for a smaller problem it will work for the current one.
 * don't try to trace the entire execution in your head, uita computer er kaaj.
 * =======================
 * step 1: always ask 3 questions?
 * - whats the simplest version of this problem? (base case)
 * - assuming i can solve a smaller version how do i use that to solve the current version (recursive case)
 * - am i going towards the base case? is my recursion algorithm going towards the base case?
 * =======================
 * step 2: solve it on paper first
 * - factorial(4)
 *      - base case reached? no. move on
 * - 4 * factorial(3)
 *          - base case reached? no move on
 *     - 3 * factorial(2)
 *              - base case reached? no move on
 *         - 2 * factorial(1)
 *                  - base case reached? yes. return 1
 *         - 2 * 1
 *     - 3 * 2 * 1
 * - 4 * 3 * 2 * 1
 */
#include <iostream>
#include <assert.h>
#include <vector>

using namespace std;

// let's break down factorial  into small problems
// what it does:
// 1 * 2 * 3 * 4 = 24
// let's start with factorial(4)
int rFactorial(int n)
{
    // step-0: think of the simplest version (base case). A factorial cannot be less than 1 or 0
    if (n == 0 || n == 1)
        return 1;

    // break into smaller steps. to return from the already in place small solution, we do a return
    return n * rFactorial(n - 1);
}

int nFactorial(int n)
{
    int ans = 1;
    // if you have a repeatitive for loop like this, you can also break it down into recursion
    for (int i = 2; i <= n; i++)
        ans *= i;
    return ans;
}

int rFibonacci(int n)
{
    if (n <= 1)
        return n;

    return rFibonacci(n - 1) + rFibonacci(n - 2);
}

string reverse_string(string str)
{
    if (str.size() <= 1 || left == right)
        return str;

    return str.back() + reverse_string(str.substr(0, str.size() - 1));
}

bool is_palindrome(string str, int left, int right)
{
    // class activity
}

int recursive_sum_n(int n)
{
    if (n == 1)
        return n;
    return n + recursive_sum_n(n - 1);
}

int binary_search(const vector<int> &arr, int left, int right, int key)
{
    if (left >= right)
        return -1;

    int mid = (left + right) / 2;

    if (arr[mid] == key)
    {
        return mid;
    }
    else if (arr[mid] > key)
    {
        return binary_search(arr, left, mid - 1, key);
    }
    else
    {
        return binary_search(arr, mid + 1, right, key);
    }
}

int main()
{
    cout << rFactorial(4) << "\n"; // recursive factorial
    cout << nFactorial(4) << "\n"; // loop factorial
    assert(rFactorial(4) == nFactorial(4));

    cout << rFibonacci(5) << "\n";
    string str = "hello";
    cout << reverse_string(str) << "\n";
    // str = "racecar";
    // cout << is_palindrome(str, 0, str.size() - 1) << "\n";
    // str = "hello";
    // cout << is_palindrome(str, 0, str.size() - 1) << "\n";
    // cout << recursive_sum_n(4) << "\n";
}