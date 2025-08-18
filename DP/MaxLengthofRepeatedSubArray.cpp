class Solution {
public:
int solve(vector<int>& nums1, vector<int>& nums2, int n, int m, vector<vector<int>>& dp, int &ans) {
    if(n==0 || m==0) return 0;

    if(dp[n][m] != -1) return dp[n][m];

    if(nums1[n-1] == nums2[m-1]) {
        dp[n][m] = 1 + solve(nums1, nums2, n-1, m-1, dp, ans);
        ans = max(ans, dp[n][m]);  
    } else {
        //the contiguous streak ends immediately  So we reset to 0 at that (n,m)

     dp[n][m] = 0;    
    }

    
    solve(nums1, nums2, n-1, m, dp, ans);
    solve(nums1, nums2, n, m-1, dp, ans);

    return dp[n][m];
}

int findLength(vector<int>& nums1, vector<int>& nums2) {
    int n = nums1.size();
    int m = nums2.size();
    vector<vector<int>> dp(n+1, vector<int>(m+1, -1));
    int ans = 0;
    solve(nums1, nums2, n, m, dp, ans);
    return ans;
}
};
