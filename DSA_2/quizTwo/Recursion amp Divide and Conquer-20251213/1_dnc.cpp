#include <iostream>
#include <vector>

using namespace std;

// the utility func for dnc
int crossing_sum(const vector<int> &arr, int left, int mid, int right)
{
    int lsum(1e-9), sum(0);
    for (int i = mid; i >= left; i--)
    {
        sum += arr[i];
        lsum = max(lsum, sum);
    }

    int rsum(1e-9);
    sum = 0;
    for (int i = mid + 1; i <= right; ++i)
    {
        sum += arr[i];
        rsum = max(rsum, sum);
    }

    return lsum + rsum;
}

int max_subarray_sum(const vector<int> &arr, int left, int right)
{
    if (left == right)
        return arr[left]; // base case -> the smallest problem to solve

    int mid = left + (right - left) / 2;                 // find midpoint
    int lsum = max_subarray_sum(arr, left, mid);         // keep breaking down the left subtree, once done, start building up the solution
    int rsum = max_subarray_sum(arr, mid + 1, right);    // keep breaking down the righ subtree, once done, start building up the solution
    int cross_sum = crossing_sum(arr, left, mid, right); // merge the sub problems

    return max(max(lsum, rsum), cross_sum); // find the most optimal solution
}

int main()
{
    vector<int> v = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    cout << max_subarray_sum(v, 0, v.size() - 1) << "\n";
}