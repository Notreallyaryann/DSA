#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    void nextPermutation(vector<int> &nums)
    {
        int ind = -1;
        int n = nums.size();
        // find the first element  from end where there is a dip
        for (int i = n - 2; i >= 0; i--)
        {
            if (nums[i] < nums[i + 1])
            {
                ind = i;
                break;
            }
        }
        if (ind == -1)
        {
            // it means there is no dip, it is lexographically the biggest one so just reverse
            reverse(nums.begin(), nums.end());
            return;
        }
        for (int i = n - 1; i > ind; i--)
        {
            if (nums[i] > nums[ind])
            {
                swap(nums[i], nums[ind]);
                break;
            }
        }
        // after the breakpoint reverse so that we get min array
        reverse(nums.begin() + ind + 1, nums.end());
    }
};