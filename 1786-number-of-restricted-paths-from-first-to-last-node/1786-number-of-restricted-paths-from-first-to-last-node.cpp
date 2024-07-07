class Solution {
public:
    int dfs(int node,int n,vector<pair<int,int>>adj[],vector<int>& dist,vector<int> &vis){
        // vis[node] = 1;
        int mod = 1e9+7;
        if(node==n){
            vis[node] = 1;
            return 1;
        }
        if(vis[node]!=-1)return vis[node];
        int ans = 0;
        for(auto it: adj[node]){
            int adjNode = it.first;
            int wt = it.second;
            if(dist[node]>dist[adjNode]){
                ans = (ans%mod + dfs(adjNode,n,adj,dist,vis)%mod)%mod;
            }
        }
        return vis[node] = ans%mod;
    }
    int countRestrictedPaths(int n, vector<vector<int>>& edges) {
        int mod = 1e9+7;
        //dijkstra to find the shortest path 
        vector<pair<int,int>> adj[n];
        int m = edges.size();
        for(int i=0;i<m;i++){
            int node1 = edges[i][0]-1;
            int node2 = edges[i][1]-1;
            int wt = edges[i][2];
            adj[node1].push_back({node2,wt});
            adj[node2].push_back({node1,wt});
        }
        vector<int> dist(n,INT_MAX);
        dist[n-1] =  0;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> q;
        q.push({0,n-1});
        while(!q.empty()){
            int dis = q.top().first;
            int node = q.top().second;
            q.pop();
            for(auto it: adj[node]){
                int adjNode = it.first;
                int adjWt = it.second;
                if(dis+adjWt<dist[adjNode]){
                    dist[adjNode] = dis+adjWt;
                    q.push({dist[adjNode],adjNode});
                }
            }
        }
        vector<int>vis(n,-1);
        return dfs(0,n-1,adj,dist,vis)%mod; 
    }
};