/*
 
 OPTIMAL SUBSTRUCTURE :
 -DP recursion
 Otimal of big problem depends on optimal of smaller problem
 
 OVERLAPPING SUBPROBLEM :
 -DP for loops
 
 for loops -> bottom up approach
 recursion -> top down approach
 
 1. Variant of Knapsack problem
 Input: x1, x2, . . . , xn (objects),
 w1, w2, . . . , wn (weights),
 W(capacity)
 Output: S ⊆ x1, x2, . . . , xn such that W(S) = P

 xi∈S wi ≤ W and the number of objects included in S

 is maximum.
 - Implement a greedy approach. If the greedy approach fails, implement a DP algorithm.
 
 Implement your approach.
 
 */
#include <iostream>
#include <vector>
using namespace std;

int dynamic (vector<pair<int,int>> &v, int ind, int weight, vector<vector<int>> &dp){
    if(weight == 0){
        return 0;
    }
    if(ind == 0){
        if(v[ind].first <= weight){
            return v[ind].second;
        }
    }
    if(dp[ind][weight] != -1){
        return dp[ind][weight];
    }
    int notChoose = dynamic(v, ind-1, weight, dp);
    int Choose = INT_MIN;
    if(v[ind].first <= weight){
        Choose = v[ind].second + dynamic(v, ind-1, weight - v[ind].first, dp);
    }
    return dp[ind][weight] = max(notChoose, Choose);
}

int main() {
    int n, w, profit, weight;
    cout << "Enter the length : "; cin >> n;
    vector<pair<int,int>> v;
    cout << "Enter the weights and profits :" << endl;
    for(int i = 0; i<n; ++i){
        cin >> w >> profit;
        v.push_back(make_pair(w, profit));
    }
    cout << "Enter the weight : "; cin >> weight;
    sort(v.begin(), v.end());
    vector<vector<int>> dp(n, vector<int>(weight+1, -1));
    int max_prft = dynamic(v, n-1, weight, dp);
    cout << max_prft << endl;
    
    return 0;
 
}
