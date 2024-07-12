class Solution {
public:
    int findMinHeightTrees(int n, vector<vector<int>>& edges) {
        //basically we can do dijkstra on each node and calculate distance-tle ka ultra pro-bekar solution
        //or we can do bfs or dfs for each node and compare their heights o(n(n+E))
        //there could be further optimisations but we have to think about them 
        //another could be to find the height of the tree and then check -o(n^2)

        //first create the adjacency list 
        //tle solution
        // vector<int> adj[n];
        // for(int i=0;i<edges.size();i++){
        //     int node1 = edges[i][0];
        //     int node2 = edges[i][1];
        //     adj[node1].push_back(node2);
        //     adj[node2].push_back(node1);
        // }
        // //now we have to check the minimum 
        // int mini = 1e9;
        // vector<int> storeBfs(n,0);
        // for(int i=0;i<n;i++){
        //     int element = bfs(i,adj,n);
        //     storeBfs[i] = element;
        //     mini = min(mini,element);
        // }
        // vector<int> ans;
        // for(int i=0;i<n;i++){
        //     if(storeBfs[i]==mini)ans.push_back(i);
        // }
        // return ans;

        //roots of the mht must be the mid point of longest leaf to leaf path in the tree 
        //also another observation there can be atmost two nodes in the middle of the path
        //this is something like topological sorting 
        //what we have to do is basically keep on removing leaf nodes
        //that will leave us with new leaf nodes
        //we have to keep removing them until we are left with either one or two nodes
        //for this we can use kahn's algo of indegrees and all
        //edge cases
        if(n<=1)return 0;
        int ans = 0;
        vector<int> adj[n];
        for(int i=0;i<edges.size();i++){
            int node1 = edges[i][0];
            int node2 = edges[i][1];
            adj[node1].push_back(node2);
            adj[node2].push_back(node1);
        }
        queue<int> q;
        vector<int> indeg(n,0);
        for(int i=0;i<n;i++){
            for(auto j: adj[i]){
                indeg[j]++;
            }
        }
        for(int i=0;i<n;i++){
            if(indeg[i]==1)q.push(i);
        }
        while(!q.empty()){
            int a = q.size();
            for(int i=0;i<a;i++){
                int node = q.front();
                q.pop();
                ans = node;
                for(auto j: adj[node]){
                    indeg[j]--;
                    if(indeg[j]==1)q.push(j);
                }
            }
        }
        return ans;
    }
    pair<int,int> dfs(int node,vector<int>& vis,vector<int> adj[]){
        vis[node] = 1;
        int ans = 1;
        int ans2 = 1;
        for(auto i: adj[node]){
            if(!vis[i]){
                int val = 1+dfs(i,vis,adj).second;
                if(val>ans){
                    ans2 = ans;
                    ans = val;
                }
                else if(val>ans2){
                    ans2 = val;
                }
            }
        }
        return {ans+ans2-1,ans};
    }
    int minimumDiameterAfterMerge(vector<vector<int>>& edges1, vector<vector<int>>& edges2) {
        //inspired by lc 310
        //find the node of minimum height tree
        //find the largest path from that node
        //find max of(largest path in tree1, largest path in tree2,largest path in tree1+tree2 combined)
        int n = edges1.size();
        int m = edges2.size();
        int x =  findMinHeightTrees(n+1,edges1);
        int y =  findMinHeightTrees(m+1,edges2);
        vector<int> vis(n+1,0);
        vector<int> vis1(m+1,0);
        vector<int> adj1[n+1];
        vector<int> adj2[m+1];
        for(int i=0;i<n;i++){
            int node1 = edges1[i][0];
            int node2 = edges1[i][1];
            adj1[node1].push_back(node2);
            adj1[node2].push_back(node1);
        }
        for(int i=0;i<m;i++){
            int node1 = edges2[i][0];
            int node2 = edges2[i][1];
            adj2[node1].push_back(node2);
            adj2[node2].push_back(node1);
        }
        pair<int,int> val1 = dfs(x,vis,adj1);
        pair<int,int> val2 = dfs(y,vis1,adj2);
        return max({val1.first,val2.first,val1.second+val2.second})-1;
    }
};