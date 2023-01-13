class Solution {
public:
    int gcd(int a, int b){
        if(b==0){
            return a;
        }    
        return gcd(b, a%b);
    }

    int minOperations(vector<int>& nums, vector<int>& nd) {
        int gd=0;
        for(auto a : nd){
            gd = gcd(gd, a);
        }
        int n = nums.size();
        sort(nums.begin(), nums.end());
        for(int i=0; i<n; i++){
            if((gd % nums[i]) == 0){
                return i;
            }
        }
        return -1;
    }
};
