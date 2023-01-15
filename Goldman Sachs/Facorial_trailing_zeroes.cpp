class Solution {
public:
    int trailingZeroes(int n) {
        int res = 0;
        int x = 5;
        while(n/x > 0){
            res += floor(n/x);
            x=x*5;
        }
        return res;
    }
};
