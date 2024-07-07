class Solution {
public:
    bool dfs(int node,vector<int> adj[],vector<int>& vis){
        for(auto i: adj[node]){
            if(!vis[i]){
                vis[i] = -1* vis[node];
                if(!dfs(i,adj,vis))return false;
            }
            else{
                if(vis[i]==vis[node])return false;
            }
        }
        return true;
    }
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        vector<int> adj[n];
        for(int i=0;i<dislikes.size();i++){
            int node1 = dislikes[i][0]-1;
            int node2 = dislikes[i][1]-1;
            adj[node1].push_back(node2);
            adj[node2].push_back(node1);
        }
        //check if graph is bipartite
        vector<int> vis(n,0);
        for(int i=0;i<n;i++){
            if(!vis[i]){
                vis[i] = 1;
                if(!dfs(i,adj,vis))return false;
            }
        }
        return true;
    }
};