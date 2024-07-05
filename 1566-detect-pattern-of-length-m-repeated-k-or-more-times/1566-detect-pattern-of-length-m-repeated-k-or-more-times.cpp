class Solution {
public:
    int solve(vector<int>& arr,int m,int k,int idx){
        int n = arr.size();
        vector<int> part(m,0);
        for(int i=idx;i<idx+m;i++){
            part[i-idx] = arr[i];
        }
        int val = 1;
        for(int i=idx+m;i<n;i=i+m){
            bool flag = true;
            for(int j=0;j<m;j++){
                if(i+j>=n || part[j]!=arr[i+j]){
                    flag = false;
                    break;
                } 
            }
            if(!flag)return false;
            val++;
            if(val>=k)return true;
        }
        return val>=k;
    }
    bool containsPattern(vector<int>& arr, int m, int k) {
        int n = arr.size();
        for(int i=0;i<n-m+1;i++){
            if(solve(arr,m,k,i))return true;
        }
        return false;
    }
}; 