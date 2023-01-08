// Combination Sum III

// Find all valid combinations of k numbers that sum up to n such that the following conditions are true:

// Only numbers 1 through 9 are used.
// Each number is used at most once.
// Return a list of all possible valid combinations. The list must not contain the same combination twice, and the combinations may be returned in any order.

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> t = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    void helper(int k, int n, int i, int sum, vector<vector<int>> &res, vector<int> temp)
    {
        if(temp.size()==k and sum == n){
            res.push_back(temp);
            return;
        }
        if(sum > n || i>=9){
            return;
        }    
        helper(k, n, i+1, sum, res, temp);
        temp.push_back(t[i]);
        helper(k, n, i+1, sum+t[i], res, temp);
        // temp.pop_back();
    }

    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> res;
        vector<int> temp;
        helper(k, n, 0, 0, res, temp);
        return res;
        
    }
};

int main(){
    int k=3, n=7;
    Solution obj;
    vector<vector<int>> res = obj.combinationSum3(k,n);
    for(auto a : res){
        for(auto x : a){
            cout << x << " ";
        }
        cout << "\n";
    }
    return 0;
}