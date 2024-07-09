class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
        double value = customers[0][1];
        int n = customers.size();
        int pre = customers[0][0]+customers[0][1];
        for(int i=1;i<n;i++){
            if(customers[i][0]>pre){
                value+=customers[i][1];
                pre=customers[i][0]+customers[i][1];
                continue;
            }
            pre += customers[i][1];
            value += pre-customers[i][0];
        }
        return value/n;
    }
};