#include<vector>
class Solution {
public:
    int passThePillow(int n, int time) {
        if(n>time){
            return (time+1);
        }
        else if(n==time){
            return (time-1);
        }
        else{
            vector<int> v1;
            for(int i=1;i<=n;i++){
                v1.push_back(i);
            }
            for(int i=n-1;i>1;i--){
                v1.push_back(i);
            }
            int a= time-(2*(n-1)*(time/(2*(n-1))));
            return v1[a];
        }
    }
};