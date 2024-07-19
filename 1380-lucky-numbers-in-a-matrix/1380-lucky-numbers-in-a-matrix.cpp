class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<int> ans;
        vector<int> row(m,INT_MAX);
        vector<int> col(n,INT_MIN);
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                row[i] = min(row[i],matrix[i][j]);
                col[j] = max(col[j],matrix[i][j]);
            }
        }
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(matrix[i][j]==row[i] && matrix[i][j]==col[j]){
                    ans.push_back(matrix[i][j]);
                }
            }
        }
        return ans;

    }
};