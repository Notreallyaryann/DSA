#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    vector<int> majorityElement(vector<int> &nums)
    {
        int n = nums.size();
        int maj1 = nums[0], maj2 = 0, c1 = 1, c2 = 0;
        // find potential candidates
        for (int i = 1; i < n; i++)
        {
            if (nums[i] == maj1)
            {
                c1++;
            }
            else if (nums[i] == maj2)
            {
                c2++;
            }
            else if (c1 == 0)
            {
                maj1 = nums[i];
                c1 = 1;
            }
            else if (c2 == 0)
            {
                maj2 = nums[i];
                c2 = 1;
            }
            else
            {
                c1--;
                c2--;
            }
        }
        c1 = c2 = 0;
        for (int i = 0; i < n; i++)
        {
            if (nums[i] == maj1)
            {
                c1++;
            }
            else if (nums[i] == maj2)
            {
                c2++;
            }
        }

        // Collect results
        vector<int> ans;
        if (c1 > n / 3)
            ans.push_back(maj1);
        if (c2 > n / 3)
            ans.push_back(maj2);

        return ans;
    }
};