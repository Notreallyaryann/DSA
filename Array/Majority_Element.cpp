#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int majorityElement(vector<int> &nums)
    {
        int n = nums.size();
        int majorityElement = nums[0];
        int vote = 1;
        for (int i = 1; i < n; i++)
        {
            if (majorityElement == nums[i])
            {
                vote++;
            }
            else
            {
                vote--;
                if (vote == 0)
                {
                    majorityElement = nums[i];
                    vote = 1;
                }
            }
        }
        return majorityElement;
    }
};