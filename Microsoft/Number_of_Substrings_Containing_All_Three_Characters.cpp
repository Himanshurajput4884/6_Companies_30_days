class Solution {
public:
    int numberOfSubstrings(string s) {
        int n = s.size();
        map<char,int> mp;
        int l=0, h=0, res=0;
        while(h<n){
            mp[s[h]]++;
            while(mp['a']>=1 && mp['b']>=1 && mp['c']>=1){
                res += 1+(n-1-h);
                mp[s[l]]--;
                l++;
            }
            h++;
        }
        return res;
    }
};
