class Solution {
public:
    vector<int> smallestSubarrays(vector<int>& nums) {
        int last[30] = {};
        int n = nums.size();
        vector<int> ans(n,1);
        for(int i=n-1;i>=0;i--){
            for(int mask = 0; mask<30;mask++){
                if(nums[i] & (1<<mask))last[mask] = i;
                ans[i] = max(ans[i],last[mask]-i+1);
            }
        }
        return ans;
    }
};