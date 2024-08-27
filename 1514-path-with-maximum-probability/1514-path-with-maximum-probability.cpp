class Solution {
public:

    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
        vector<pair<int,double>> adj[n];
        for(int i=0;i<edges.size();i++){
            int edge1 = edges[i][0];
            int edge2 = edges[i][1];
            double wt = succProb[i];
            adj[edge1].push_back({edge2,wt});
            adj[edge2].push_back({edge1,wt});
        }
        //dist, node
        //max heap ?
        priority_queue<pair<double,int>> pq;
        vector<double>dist(n,0);
        pq.push({1,start_node});
        dist[start_node] = 0; 
        while(!pq.empty()){
            double dis = pq.top().first;
            int node = pq.top().second;
            pq.pop();
            for(auto i: adj[node]){
                int adjNode = i.first;
                double edgeWt = i.second;
                double val = edgeWt*dis;
                if(val>dist[adjNode]){
                    dist[adjNode] = val;
                    pq.push({dist[adjNode],adjNode});
                }
            }
        }
        return dist[end_node];
    }
};