// Shortest Unsorted Continuous Subarray

// Given an integer array nums, you need to find one continuous subarray that if you only sort this subarray in ascending order, then the whole array will be sorted in ascending order.

// Return the shortest such subarray and output its length.

// code 
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        vector<int> d = nums;
        sort(d.begin(), d.end());
        int l = 0;
        int h = nums.size()-1;
        while(l!=nums.size() and nums[l]==d[l]){
            l++;
        }
        if(l==nums.size()){
            return 0;
        }
        while(h>=0 and nums[h]==d[h]){
            h--;
        }
        return (h-l+1); 
    }
};

int main(){
    vector<int> nums = {2,6,4,8,10,9,15};
    Solution obj;
    cout << obj.findUnsortedSubarray(nums) << endl;
    return 0;
}