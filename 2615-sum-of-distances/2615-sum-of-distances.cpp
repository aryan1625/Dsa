class Solution {
public:
    vector<long long> distance(vector<int>& nums) {
        unordered_map<int,vector<int>> um;
        int n = nums.size();
        vector<long long> ans(n,0);
        for(int i=0;i<n;i++){
            um[nums[i]].push_back(i);
        }
        for(auto it: um){
            int a = it.second.size();
            long long int val = 0;
            for(int i=0;i<a;i++){
                val += it.second[i];
            }
            ans[it.second[0]] = val-a*it.second[0];
            long long int val2 = it.second[0];
            for(int i=1;i<a;i++){
                ans[it.second[i]] = val+(long long int)it.second[i]*(2*i-a)-2*val2;
                val2 += it.second[i];
            }
        }
        return ans;
    }
};