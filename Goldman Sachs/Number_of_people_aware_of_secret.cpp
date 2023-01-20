class Solution {
public:
    int mod = 1e9+7;
    long long helper(vector<int> &dp, int n, int delay, int forget){
        int a = forget-delay;
        long long sum = 0, j=0;
        if(dp[n] != -1){
            return dp[n];
        }
        while(a>0 && n-delay-j>0){
            sum += helper(dp,n-delay-j,delay,forget);
            sum = sum%mod;
            a--;
            j++;
        }
        if(n-forget > 0){
            dp[n] = sum%mod;
        }
        else{
            dp[n] = (sum+1)%mod;
        }
        return dp[n];
    }
    int peopleAwareOfSecret(int n, int delay, int forget) {
        vector<int> dp(n+1, -1);
        return helper(dp,n,delay,forget);
    }
};
