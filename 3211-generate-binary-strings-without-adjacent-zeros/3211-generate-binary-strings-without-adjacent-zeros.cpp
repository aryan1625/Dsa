class Solution {
public:
    void solve(int k,vector<string> &ans,string s,bool flag){
        if(k==0){
            ans.push_back(s);
            return ;
        }
        if(flag==true){
            s+='1';
            solve(k-1,ans,s,true);
            s.pop_back();
            
            s+='0';
            solve(k-1,ans,s,false);
            s.pop_back();
        }
        else{
            s+='1';
            solve(k-1,ans,s,true);
            s.pop_back();
        }
        return ;
        
    }
    vector<string> validStrings(int n) {
        vector<string> ans;
        string s;
        solve(n,ans,s,true);
        return ans;
    }
};