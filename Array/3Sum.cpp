#include <iostream>
#include <vector>
#include <set>
using namespace std;
class Solution
{
public:
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        int n = nums.size();
        set<vector<int>> temp_set;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < n - 2; i++)
        { // unique chahiye
            int j = i + 1, k = n - 1;
            while (j < k)
            {
                int sum = nums[i] + nums[j] + nums[k];
                if (sum == 0)
                {
                    temp_set.insert({nums[i], nums[j], nums[k]});
                    j++, k--;
                }
                else if (sum > 0)
                {
                    k--;
                }
                else
                {
                    j++;
                }
            }
        }
        vector<vector<int>> ans;
        for (auto &one_d_array : temp_set)
        {
            ans.push_back(one_d_array);
        }

        return ans;
    }
};