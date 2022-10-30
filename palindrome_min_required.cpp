/*
 
 OPTIMAL SUBSTRUCTURE :
 -DP recursion
 Otimal of big problem depends on optimal of smaller problem
 
 OVERLAPPING SUBPROBLEM :
 -DP for loops
 
 for loops -> bottom up approach
 recursion -> top down approach
 
 4. Input: A string x
 Question: Find the minimum number of characters that needs to be inserted to make x a palindrome.

 Implement your approach.
 
 */
#include <iostream>
#include <vector>
using namespace std;

int getMin(string s, int first, int last, vector<vector<int>> &dp){
    if(first > last){
        return INT_MAX;
    }
    if(s[first] == s[last]){
        return 0;
    }
    if(s[first] == s[last-1]){
        return (s[last] == s[first] ? 0:1);
    }
    if(dp[first][last] != -1){
        return dp[first][last];
    }
    else{
        return dp[first][last] = min(getMin(s, first+1, last, dp), getMin(s, first, last-1, dp)) + 1;
        //return min(getMin(s, first+1, last, dp), getMin(s, first, last-1, dp)) + 1;
    }
}


int main() {
    string s;
    cout << "Enter the string : "; cin >> s;
    vector<vector<int>> dp(s.length(), vector<int>(s.length(), -1));
    //cout << (s.length()) << endl;
    int minimum = getMin(s, 0, s.length()-1, dp);
    cout << minimum << endl;
    
    return 0;
    
}
