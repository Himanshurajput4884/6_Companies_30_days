class Solution {
public:
    int numberOfBoomerangs(vector<vector<int>>& p) {
        int res =0;
        for(int i=0; i<p.size(); i++){
            map<int, int> mp;
            for(int j=0; j<p.size(); j++){
                if(i!=j){
                    int d = (p[i][0]-p[j][0])*(p[i][0]-p[j][0]) + (p[i][1]-p[j][1])*(p[i][1]-p[j][1]);
                    mp[d]++;
                }
            }
                for(auto a : mp){
                    if(a.second >= 2){
                        res += a.second*a.second-a.second;
                    }
                }
        }
        return res;
    }
};
