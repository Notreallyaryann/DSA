#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int maxSubArray(vector<int> &nums)
    {
        int sum = 0;
        int maxi = INT_MIN;
        int n = nums.size();
        for (int i = 0; i < n; i++)
        {
            sum += nums[i];
            if (sum > maxi)
            {
                maxi = sum;
            }
            // if the sum becomes 0 then their is no point in taking forward that array so update sum=0
            if (sum < 0)
            {
                sum = 0;
            }
        }
        return maxi;
    }
};