class Solution {
public:
    int solve(int idx,vector<int> &nums,vector<int>& dp){
        int n = nums.size();
        if(idx>=n)return 0;
        int val = nums[idx];
        if(val+idx>=n-1)return 1;
        if(dp[idx]!=-1)return dp[idx];
        int mini = 1e9;
        for(int j = idx+1;j<=idx+val;j++){
            mini = min(mini,1+solve(j,nums,dp));
        }
        return dp[idx] =mini;
    }
    int jump(vector<int>& nums) {
        int n =nums.size();
        if(n==1)return 0;
        vector<int> dp(n,-1);
        return solve(0,nums,dp);
    }
};
