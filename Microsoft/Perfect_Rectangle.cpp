// Perfect Rectangle

// Given an array rectangles where rectangles[i] = [xi, yi, ai, bi] represents an axis-aligned rectangle. The bottom-left point of the rectangle is (xi, yi) and the top-right point of it is (ai, bi).

// Return true if all the rectangles together form an exact cover of a rectangular region.

// code 

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isRectangleCover(vector<vector<int>>& rect) {
        map<pair<int,int>, int> mp;
        for(auto a : rect){
            mp[{a[0],a[1]}]++;
            mp[{a[2],a[3]}]++;
            mp[{a[0],a[3]}]--;
            mp[{a[2],a[1]}]--;
        }
        int count=0;
        for(auto a :mp){
            count += abs(a.second);
        }
        return count==4;
    }
};

int main(){
    Solution obj;
    vector<vector<int>> rect = {{1,1,3,3},{3,1,4,2},{3,2,4,4},{1,3,2,4},{2,3,3,4}};
    cout << obj.isRectangleCover(rect) << endl;
    return 0;
}