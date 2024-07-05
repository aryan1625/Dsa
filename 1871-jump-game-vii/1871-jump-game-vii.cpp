class Solution {
public:
    bool canReach(string s, int minJump, int maxJump) {
        int n = s.size();
        if(s[n-1]=='1')return false;
        vector<int> val;
        val.push_back(0);
        for(int i=1;i<n;i++){
            if(s[i]=='0'){
                for(int j=val.size()-1;j>=0;j--){
                    if(val[j]+minJump<=i && i<=val[j]+maxJump){
                        val.push_back(i);
                        break;
                    }
                }
            }
        }
        return val.back()==n-1;
    }
};