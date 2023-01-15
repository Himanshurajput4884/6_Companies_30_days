class Solution {
public:
    int minimumCardPickup(vector<int>& cards) {
        int res = INT_MAX;
        map<int,int> mp;
        for(int i=0; i<cards.size(); i++){
            if(mp.find(cards[i]) == mp.end()){
                mp[cards[i]] = i;
            }
            else{
                res = min(res, i-mp[cards[i]]);
                mp[cards[i]] = i;
            }
        }   
        return res==INT_MAX ? -1 : res+1;
    }
};
