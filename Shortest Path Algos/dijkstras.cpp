class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<pair<int, int>> adj[n+1];
        for(auto it : times){
            adj[it[0]].push_back({it[1], it[2]});
        }
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        vector<int> dist(n+1, INT_MAX);
        dist[k] = 0;
        pq.push({dist[k], k});

        while(!pq.empty()){
            auto ele = pq.top();
            pq.pop();
            int d = ele.first;
            int node = ele.second;
            for(auto it : adj[node]){
                int adjNode = it.first;
                int new_d = it.second;
                if(dist[adjNode] > d + new_d){
                    dist[adjNode] = d + new_d;
                    pq.push({d + new_d, adjNode});
                }
            }
        }

        for(int i = 1; i <= n; i++){ cout << dist[i] << " ";}cout << endl;

        int maxi = INT_MIN;
        for(int i = 1; i <= n; i++){
            if(i != k && dist[i] == INT_MAX) return -1;
            maxi = max(maxi, dist[i]);
        }

        return maxi;
    }
};
