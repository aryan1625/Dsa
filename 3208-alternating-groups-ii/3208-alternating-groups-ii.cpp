class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& colors, int k) {
        int n = colors.size();
        int ans = 0;
        vector<int> val(n+k-1,0);
        for(int i=0;i<n+k-1;i++){
            val[i] = colors[(i+k)%n];
        }
        int pre = 1;
        for(int i=1;i<n+k-1;i++){
            if(val[i]!=val[i-1]){
                pre++;
            }
            else{
                pre = 1;
            }
            if(pre>=k)ans++;
        }
        return ans;
    }
};