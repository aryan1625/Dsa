class Solution {
public:
    int minOperations(vector<string>& logs) {
        int val = 0;
        int n = logs.size();
        for(int i=0;i<n;i++){
            if(logs[i]=="../"){
                val=val==0?0:val-1;
            }
            else if(logs[i]=="./"){
                continue;
            }
            else{
                val++;
            }
        }
        return val;
    }
};