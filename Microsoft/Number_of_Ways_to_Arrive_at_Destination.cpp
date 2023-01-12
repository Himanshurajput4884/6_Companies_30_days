#define ll long long int
#define pll pair<ll, ll>
class Solution {
public:
    int mod = 1e9+7;
    int dijkstra(vector<vector<pll>> &graph, int n){
        vector<ll> dist(n, LONG_MAX);
        vector<ll> ways(n);
        dist[0] = 0;
        ways[0] = 1;
        priority_queue<pll, vector<pll>, greater<>> pq;
        pq.push({0,0});   // {dist, node}
        while(!pq.empty()){
            auto [d, u] = pq.top();
            pq.pop();
            if(d > dist[u]){
                continue;
            }
            for(auto [v,w] : graph[u]){
                if(dist[v] > d + w){
                    dist[v] = d + w;
                    ways[v] = ways[u];
                    pq.push({dist[v], v});
                }
                else if(dist[v] == d+w){
                    ways[v] = (ways[v]+ways[u])%mod;
                }
            }
        }
        return ways[n-1];
    }

    int countPaths(int n, vector<vector<int>>& roads) {
        vector<vector<pll>> graph(n);
        for(auto a : roads){
            graph[a[0]].push_back({a[1], a[2]});
            graph[a[1]].push_back({a[0], a[2]});
        }
        return dijkstra(graph, n);
    }
};
