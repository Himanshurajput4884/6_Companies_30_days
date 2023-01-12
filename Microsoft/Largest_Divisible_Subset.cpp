//  Largest Divisible Subset

// Given a set of distinct positive integers nums, return the largest subset answer such that every pair (answer[i], answer[j]) of elements in this subset satisfies:

// answer[i] % answer[j] == 0, or
// answer[j] % answer[i] == 0
// If there are multiple solutions, return any of them.

// Code:

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<int> dp(n, 1);
        int mx=1, x=-1;
        for(int i=0; i<n; i++){
            for(int j=0; j<i; j++){
                if(nums[i]%nums[j]==0 && dp[i]<dp[j]+1){
                    dp[i] = dp[j]+1;
                    if(mx < dp[i]){
                        mx = dp[i];
                    }
                }
            }
        }
        vector<int> res;
        for(int i=n-1; i>=0; i--){
            if(mx==dp[i] && (x==-1 || (x%nums[i]==0))){
                res.push_back(nums[i]);
                mx--;
                x=nums[i];
            }
        }
        return res;
    }
};


int main(){
    Solution obj;
    vector<int> nums = {1,2,4,8};
    vector<int> res = obj.largestDivisibleSubset(nums);
    for(auto a : res){
        cout << a << " ";
    }
    return 0;
}