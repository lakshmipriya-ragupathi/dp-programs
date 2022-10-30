/*
1.  Input: an integer x, denominations d1,d2,...,dk
Question: Find number of different ways to give change for x by using d1,d2,...,dk.

Although there is no optimization involved, does there exists overlapping subproblem?
Is this a candidate for DP?  If yes, Implement a DP solution, otherwise implement your approach.
 
 
 we fill the table in such a way:
 tb[row][column] = tb[row][col - coins[row-1] + tb[row-1][col]
 
 tb[row][col - coins[row-1] add this only if it exists
            change
 value:     ind:    0   1   2   3   4   5
 {}         0       1   0   0   0   0   0
 {1}        1       1   1   1   1   1   1
 {1,2}      2       1   1   2   2   3   3
 {1,2,5}    3       1   1   2   2   3   4
 
 */
#include <iostream>
#include <vector>
using namespace std;


int main() {
    int n,z,v;
    vector <int> denom;
    cout << "Enter the number of denominations : ";cin >> n;
    for(int i=0; i<n; ++i){
        cin>>v;
        denom.push_back(v);
    }
    cout << "Enter the changing amount : "; cin >> z;
    vector<vector<int>> dp(n+1, vector<int>(z+1, -1));
    
   for(int i=0; i<n; ++i){
        for(int j=0; j<=z; ++j){
            if(j==0){
                dp[i][j] = 1;
            }
            if(i==0){
                if(denom[i] <= j){
                    dp[i][j] = 1;
                }
            }
            
            else{
                if(dp[i][j] == -1){
                   
                    dp[i][j] = dp[i-1][j];
                    if(j - denom[i] >= 0){
                    dp[i][j] = dp[i][j] + dp[i][j - denom[i]];
                    }
                }
                }
            cout << dp[i][j] << " ";
        }
       cout << endl;
    }
    
    cout << "number of ways" << dp[n-1][z] << endl;
    
    return 0;
}
