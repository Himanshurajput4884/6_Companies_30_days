// Course Schedule

// There are a total of numCourses courses you have to take, labeled from 0 to numCourses - 1. You are given an array prerequisites where prerequisites[i] = [ai, bi] indicates that you must take course bi first if you want to take course ai.

// For example, the pair [0, 1], indicates that to take course 0 you have to first take course 1.
// Return true if you can finish all courses. Otherwise, return false.

// Code:

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    //              DFS ALGO TO FIND TOPOLOGICAL SORT
    
    // void top_sort(vector<int> graph[], vector<int> &res, int n, vector<bool> &visited, int i){
    //     visited[i] = true;
    //     for(auto a : graph[i]){
    //         if(!visited[a]){
    //             top_sort(graph, res, n, visited, a);
    //         }
    //     }
    //     res.push_back(i);
    // }
    // bool canFinish(int n, vector<vector<int>>& p) {
    //     vector<int> graph[n];
    //     for(vector<int> a : p){
    //         graph[a[1]].push_back(a[0]);
    //     }
    //     vector<bool> visited(n, false);
    //     vector<int> res;
    //     for(int i=0; i<n; i++){
    //         if(!visited[i]){
    //             top_sort(graph, res, n, visited, i);
    //         }
    //     }
    //     if(res.size() != n){
    //         return false;
    //     }
    //     return true;
    // }
    
    //                  KAHN'S ALGO TO FIND TOPOLOGICAL SORT
    
    bool canFinish(int n, vector<vector<int>>& p){
        vector<int> graph[n];
        for(vector<int> a : p){
            graph[a[1]].push_back(a[0]);
        }
        vector<int> indegree(n);
        vector<int> res;
        for(int i=0; i<n; i++){
            for(int j=0; j<graph[i].size(); j++){
                indegree[graph[i][j]]++;
            }
        }
        queue <int> q;
        for(int i=0; i<n; i++){
            if(indegree[i] == 0){
                q.push(i);
            }
        }
        while(!q.empty()){
            int u = q.front();
            q.pop();
            res.push_back(u);
            for(auto i=graph[u].begin(); i<graph[u].end(); i++){
                indegree[*i]--;
                if(indegree[*i] == 0){
                    q.push(*i);
                }
            }
        }
        // cout<<res.size();
        // for(int i=0; i<res.size(); i++){
        //     cout<<res[i]<<" ";
        // }
        if(res.size() == n){
            return true;
        }
        return false;
    }
};

int main(){
    Solution obj;
    int n = 2;
    vector<vector<int>> p = {{1,0}};
    cout << obj.canFinish(n, p);
    return 0;
}