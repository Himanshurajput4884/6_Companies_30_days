class Solution {
public:
    bool isPossible(vector<int>& nums) {
        int n = nums.size();
        map<int, int> mp;
        for(auto a : nums){
            mp[a]++;
        }
        int mx=0;
        for(auto a : mp){
            mx = max(mx, a.second);
        }
        if(n/mx < 3){
            return false;
        }
        vector<int> data(mx, -10000);
        priority_queue<int, vector<int>, greater<int>> pq;
        for(auto a : nums){
            pq.push(a);
        }
        int i=0;
        int t = mx;
        while(t--){
            data[i]=pq.top();
            pq.pop();
            i=(i+1)%mx;
        }
        while(!pq.empty()){
            if(pq.top() != data[i]+1){
                return false;
            }
            else{
                data[i] = pq.top();
                pq.pop();
                i=(i+1)%mx;
            }
        }
        return true;
    }
};
