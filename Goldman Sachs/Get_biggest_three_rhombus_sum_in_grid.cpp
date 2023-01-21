class Solution {
public:
    vector<int> getBiggestThree(vector<vector<int>>& grid) {
        priority_queue<int> pq;
        int n = grid.size(), m = grid[0].size();
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                pq.push(grid[i][j]);
                int t = min(i, min(j, min(n-1-i, m-1-j)));
                int x = i-t, x0=i+t;
                while(x != i){
                    int x1 = x;
                    int sum = 0, k=0;
                    while(x1 <= i){
                        if(!k){
                            sum += grid[x1][j-k];
                        }
                        else{
                            sum += grid[x1][j-k]+grid[x1][j+k];
                        }
                        k++, x1++;
                    }
                    x1 = x0, k=0;
                    while(x1 != i){
                        if(!k){
                            sum += grid[x1][j-k];
                        }
                        else{
                            sum += grid[x1][j-k]+grid[x1][j+k];
                        }
                        k--, x1--;
                    }
                    pq.push(sum); 
                    x++, x0--;  
                }
            }
        }
        vector<int> res;
        while(res.size()!=3 && !pq.empty()){
            int x = pq.top(); pq.pop();
            bool f=true;
            for(auto a : res){
                if(a == x){
                    f=false;
                }
            }
            if(f){
                res.push_back(x);
            }
        }
        return res;
    }
};
