class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        int n = profits.size();
        vector<pair<int,int>> data;
        for(int i=0; i<n; i++){
            data.push_back({capital[i], profits[i]});
        }
        sort(data.begin(), data.end());
        priority_queue<int> pq;
        int tt=0;
        for(int i=0; i<k; i++){
            while(tt<n && w >= data[tt].first){
                pq.push(data[tt].second);
                tt++;
            }
            if(pq.size()){
                w += pq.top();
                pq.pop();
            }
        }
        return w;
    }
};
