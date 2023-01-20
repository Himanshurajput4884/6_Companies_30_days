class Solution {
public:
    int mod = 1e9+7;
    // nums[i]-rev(nums[i]) = nums[j]-rev(nums[j]);
    int rev(int x){
        int r=0;
        while(x){
            r = r*10 + x%10;
            x=x/10;
        }
        return r;
    }
    int countNicePairs(vector<int>& nums) {
        int n = nums.size();
        vector<int> data;
        for(auto a : nums){
            data.push_back(a-rev(a));
        }
        map<long long,long long> mp;
        for(auto a : data){
            mp[a]++;
        }      
        long long res = 0;
        for(auto a : mp){
            res = res + (a.second*(a.second-1))/2;
            res = res%mod;
        }
        return res;
    }
};
