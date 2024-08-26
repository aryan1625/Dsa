class Solution {
public:
    void dfs(int x,int y,vector<vector<int>>& grid,vector<vector<int>>& vis){
        vis[x][y] = 1;
        int n = grid.size();
        int m = grid[0].size();
        int arr1[4] = {1,0,-1,0};
        int arr2[4] = {0,1,0,-1};
        for(int i=0;i<4;i++){
            int newX = x+arr1[i];
            int newY = y+arr2[i];
            if(newX>=0 && newY>=0 && newX<n && newY<m && grid[newX][newY]==1 && !vis[newX][newY]){
                dfs(newX,newY,grid,vis);
            }
        }
        return ;
    }
    int numberOfIslands(vector<vector<int>>& grid){
        int n = grid.size();
        int m = grid[0].size();
        int ans = 0;
        vector<vector<int>> vis(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1 && !vis[i][j]){
                    dfs(i,j,grid,vis);
                    ans++;
                }
            }
        }
        return ans;
    }
    int minDays(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int val = numberOfIslands(grid);
        if(val==1){
            for(int i=0;i<n;i++){
                for(int j=0;j<m;j++){
                    if(grid[i][j]==1){
                        grid[i][j] = 0;
                        int cnt = numberOfIslands(grid);
                        if(cnt>1 || !cnt)return 1;
                        grid[i][j] = 1;
                    }
                }
            }
        }else{
            return 0;
        }    
        return 2;
    }
};