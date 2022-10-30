/*
 
 OPTIMAL SUBSTRUCTURE :
 -DP recursion
 Otimal of big problem depends on optimal of smaller problem
 
 OVERLAPPING SUBPROBLEM :
 -DP for loops
 
 for loops -> bottom up approach
 recursion -> top down approach
 
 Input: Set of activities (with start time and end time) and associated weights
Question: Choose the set of non-overlapping activities that will maximize the total weight.

Will the greedy strategy discovered for 2 work for 3 as well?  or find a greedy strategy.  If greedy fails, Implement DP.
 
 if compatible make it x
compare compatible (chosen) with row above(not chosen)
 
 */
#include <iostream>
#include <vector>
using namespace std;


int main() {
    int n, start, end, weight, cur_w = 0, l;
    cout << "Enter the number of activities : "; cin >> n;
    vector<pair<int, int>> v;
    vector<pair<int, int>> w;
    for(int i=0; i<n; ++i){
        cin >> start >> end >> weight;
        v.push_back(make_pair(end, start));
        w.push_back(make_pair(end,weight));
    }
    sort(v.begin(), v.end());
    sort(w.begin(), w.end());
    vector<vector<int>> dp (n, vector<int>(n+1, -1));
    //int k =1, l=k+1;
    for(int i=0; i<n; ++i){
        for(int j=0; j<=n; ++j){
            if(j == 0){
                dp[i][j] = 0;
            }
            if(i == 0){
                dp[i][j] = w[0].second;
            }
            else{
                if(dp[i][j] == -1){
                    /*if(v[i].second >= v[i-1].first) {
                        x = dp[i-1][j] + w[i].second;
                    }*/
                    cur_w = w[i].second;
                    l = i;
                   // cout << "current index " << i << " current weight " << w[l].second << endl;
                    for(int k=i-1; k>=0; --k){
                        if(v[l].second >= v[k].first){
                            cur_w += w[k].second;
                          //  cout << "current index " << i << " chosen weight " << w[k].second << endl;
                            l = k;
                        }
                        
                    }
                    //cur_max = max(cur_w, dp[i][j-1]);
                    dp[i][j] = max(max(cur_w, dp[i-1][j]),dp[i][j-1]) ;
                    cur_w = 0;
                }
            }
            cout << dp[i][j] <<" ";
        }
        cout << endl;
    }
    
    
    return 0;
    
}
