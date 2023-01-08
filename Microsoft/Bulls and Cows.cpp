// Bulls and Cows

// You are playing the Bulls and Cows game with your friend.

// You write down a secret number and ask your friend to guess what the number is. When your friend makes a guess, you provide a hint with the following info:

// The number of "bulls", which are digits in the guess that are in the correct position.
// The number of "cows", which are digits in the guess that are in your secret number but are located in the wrong position. Specifically, the non-bull digits in the guess that could be rearranged such that they become bulls.
// Given the secret number secret and your friend's guess guess, return the hint for your friend's guess.

// The hint should be formatted as "xAyB", where x is the number of bulls and y is the number of cows. Note that both secret and guess may contain duplicate digits.


// Code:
#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    string getHint(string secret, string guess) {
        map<char,int> mp1, mp2;
        for(auto a : secret){
            mp1[a]++;
        }
        for(auto a : guess){
            mp2[a]++;
        }
        int n = 0;
        for(auto a : mp1){
            if(mp2.find(a.first)!=mp2.end()){
                n += min(mp2[a.first], mp1[a.first]);
            }
        }
        int x = 0;
        for(int i=0; i<secret.size(); i++){
            if(secret[i] == guess[i]){
                x++;
            }
        }
        int y=n-x;
        return to_string(x)+"A"+to_string(y)+"B";
    }
};

int main(){
    Solution obj;
    cout << obj.getHint("1807", "7810") << endl;
    return 0;
}