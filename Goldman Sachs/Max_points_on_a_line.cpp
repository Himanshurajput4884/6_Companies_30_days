class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int n = points.size();
        int res = 1;
        for(int i=0; i<n; i++){
            map<double,int> mp;
            for(int j=i+1; j<n; j++){
                double slop=(points[j][1]-points[i][1])/(double)(points[j][0]-points[i][0]);
                if(points[j][1]-points[i][1]<0 && points[j][0]-points[i][0]==0){
                    mp[abs(slop)]++;
                }
                else{
                    mp[slop]++;
                }
            }
            int ans = 0;
            for(auto a : mp){
                ans = max(ans, a.second);
            }
            res = max(res, ans+1);
        }
        
        return res;
    }
};