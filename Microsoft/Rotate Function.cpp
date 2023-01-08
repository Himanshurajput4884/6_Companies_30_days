// Rotate Function

// You are given an integer array nums of length n.

// Assume arrk to be an array obtained by rotating nums by k positions clock-wise. We define the rotation function F on nums as follow:

// F(k) = 0 * arrk[0] + 1 * arrk[1] + ... + (n - 1) * arrk[n - 1].
// Return the maximum value of F(0), F(1), ..., F(n-1).

// The test cases are generated so that the answer fits in a 32-bit integer.

// Code:
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        int n = nums.size();
        int sum = 0, sum1=0;
        for(int i=0; i<n; i++){
            sum += nums[i];
            sum1 += nums[i]*i;
        }
        int res=sum1;
        for(int i=n-1; i>=0; i--){
            sum1 = (sum1 + sum) - nums[i]*n;
            res = max(res, sum1);
        }
        return res;
    }
};

int main(){
    Solution obj;
    vector<int> nums = {4,3,2,6};
    cout << obj.maxRotateFunction(nums) << endl;
    return 0;  
}