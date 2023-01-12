// Number of Pairs Satisfying Inequality

// You are given two 0-indexed integer arrays nums1 and nums2, each of size n, and an integer diff. Find the number of pairs (i, j) such that:

// 0 <= i < j <= n - 1 and
// nums1[i] - nums1[j] <= nums2[i] - nums2[j] + diff.
// Return the number of pairs that satisfy the conditions.

// code 
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long res = 0;
    void combine(vector<int> &arr,int start, int mid, int end, int d){
        int l = start, h = mid+1;
        while(l<=mid && h<=end){
            if(arr[l] <= arr[h]+d){
                res += (end-h+1);
                l++;
            }
            else{
                h++;
            }
        }
        sort(arr.begin()+start, arr.begin()+end+1);
    }

    void merge_sort(vector<int> &arr, int start, int end, int d){
        if(start == end){
            return;
        }
        int mid = start + (end-start)/2;
        merge_sort(arr,start,mid,d);
        merge_sort(arr,mid+1,end,d);
        combine(arr,start,mid,end,d);
    }
    long long numberOfPairs(vector<int>& nums1, vector<int>& nums2, int diff) {
        int n = nums1.size();
        vector<int> data(n, 0);
        for(int i=0; i<n; i++){
            data[i] = (nums1[i] - nums2[i]);
        }
        merge_sort(data,0,n-1,diff);
        return res;
    }
};

int main(){
    vector<int> nums1 = {3,2,5};
    vector<int> nums2 = {2,2,1};
    int diff = 1;
    Solution obj;
    cout << obj.numberOfPairs(nums1, nums2, diff) << endl;
    return 0;
}