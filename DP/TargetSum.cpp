class Solution {
public:
    int S;
    int solve(vector<int>& nums, int &target, int i, int sum, vector<vector<int>>& dp) {
        if(i == nums.size()) {
            if(sum==target) return 1;
            else return 0;
        }

        if(dp[i][sum+S] != -1) {
            return dp[i][sum+S];
        }
        int plus  = solve(nums, target, i+1, sum+nums[i], dp);
        int minus = solve(nums, target, i+1, sum-nums[i], dp);

        return dp[i][sum+S] = plus+minus;
    }

    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        S = accumulate(begin(nums), end(nums), 0);
        vector<vector<int>> dp(n, vector<int>(2*S+1, -1));
        return solve(nums, target, 0, 0, dp);
    }
};