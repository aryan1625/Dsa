class Solution {
public:
    int numWaterBottles(int k, int e) {
        int ans = k;
        while(k>=e){
            ans += k/e;
            k = k/e + k%e;
        }
        return ans;
    }
};