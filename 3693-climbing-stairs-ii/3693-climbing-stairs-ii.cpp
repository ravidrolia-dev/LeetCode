class Solution {
public:
    int helper(int n , vector<int>& costs , vector<int>& dp){
        if(n == 0)return 0;
        if(dp[n] != -1)return dp[n];
        int ans = INT_MAX;
        for(int i = 1 ; i<=3 ; i++){
            if(n-i >= 0){
                int curr = helper(n-i,costs,dp) + costs[n-1] + i*i;
                ans = min(ans,curr);
            }
        }
        return dp[n] = ans;
    }
    int climbStairs(int n, vector<int>& costs) {
        vector<int> dp(n+1,-1);
        return helper(n,costs,dp);
    }
};