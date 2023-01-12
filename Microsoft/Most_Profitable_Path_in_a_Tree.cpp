// Most Profitable Path in a Tree

// There is an undirected tree with n nodes labeled from 0 to n - 1, rooted at node 0. You are given a 2D integer array edges of length n - 1 where edges[i] = [ai, bi] indicates that there is an edge between nodes ai and bi in the tree.

// At every node i, there is a gate. You are also given an array of even integers amount, where amount[i] represents:

// the price needed to open the gate at node i, if amount[i] is negative, or,
// the cash reward obtained on opening the gate at node i, otherwise.
// The game goes on as follows:

// Initially, Alice is at node 0 and Bob is at node bob.
// At every second, Alice and Bob each move to an adjacent node. Alice moves towards some leaf node, while Bob moves towards node 0.
// For every node along their path, Alice and Bob either spend money to open the gate at that node, or accept the reward. Note that:
// If the gate is already open, no price will be required, nor will there be any cash reward.
// If Alice and Bob reach the node simultaneously, they share the price/reward for opening the gate there. In other words, if the price to open the gate is c, then both Alice and Bob pay c / 2 each. Similarly, if the reward at the gate is c, both of them receive c / 2 each.
// If Alice reaches a leaf node, she stops moving. Similarly, if Bob reaches node 0, he stops moving. Note that these events are independent of each other.
// Return the maximum net income Alice can have if she travels towards the optimal leaf node.

// Code

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> graph[100005];
    int parent[100005];
    int dp[100005];
    int dis[100005];
    void dfs(int i, int p){
        parent[i] = p;
        for(auto a : graph[i]){
            if(a != p){
                dfs(a, i);
            }
        }

    }

    int helper(int i, vector<int>& amo, int time, int p){
        int res = -1e9;
        if(dis[i] != -1){
            if(dis[i] < time){
                res = 0;
            }
            else if(dis[i] > time){
                res = amo[i];
            }
            else if(dis[i]==time){
                res = amo[i]/2;
            }
        }
        else{
            res = amo[i];
        }
        int ans = -1e9;
        bool f=false;
        for(auto a : graph[i]){
            if(a != p){
                f=true;
                ans = max(ans, helper(a,amo,time+1,i));
            }
        }
        if(!f){
            ans = 0;
        }
        res += ans;
        return dp[i] = res;
    }

    int mostProfitablePath(vector<vector<int>>& edges, int bob, vector<int>& amo) {
        for(auto a : edges){
            graph[a[0]].push_back(a[1]);
            graph[a[1]].push_back(a[0]);
        }
        memset(dp, -1, sizeof(dp));
        memset(dis, -1, sizeof(dis));
        dfs(0, -1);
        vector<int> path;
        int x = bob;
        while(x!=0){
            path.push_back(x);
            x = parent[x];
        }
        path.push_back(0);
        int t = path.size();
        for(int i=0; i<t; i++){
            dis[path[i]] = i;
        }
        int res = helper(0,amo,0,-1);
        return res;
    }
};

int main(){
    vector<vector<int>> edges = {{0,1},{1,2},{1,3},{3,4}};
    int bob = 3;
    vector<int> amount = {-2,4,2,-4,6};
    Solution obj;
    cout << "called";
    cout << obj.mostProfitablePath(edges, bob, amount) << endl;
    return 0;
}