/*
 
 OPTIMAL SUBSTRUCTURE :
 -DP recursion
 Otimal of big problem depends on optimal of smaller problem
 
 OVERLAPPING SUBPROBLEM :
 -DP for loops
 
 for loops -> bottom up approach
 recursion -> top down approach
 
 
 2.  Input: Set of activities (with start time and end time)
 Question: Choose the set of non-overlapping activities that will maximize the number of activities done.


 Can you find a greedy strategy. Implement it.
  GREEDY !!!
 start:     11   15   16    18
 finish:    13   16   19    19
 sort by finish time
 
 choose the first one anyway
 if(start of next <= finsh of prev)
 choose!!!

 */
#include <iostream>
#include <vector>
using namespace std;


int main() {
    int n, end, start;
    cout << "Enter the total number of activities : "; cin >> n;
    vector<pair<int, int>> v;
    for(int i=0; i<n; ++i){
        cin >> start >> end;
        v.push_back(make_pair(end, start));
    }
    
    sort(v.begin(), v.end());
    for(int i=0; i<n; ++i){
            cout << v[i].second << " " << v[i].first << endl;
        }
        cout << endl;
    int k = 0;
    cout << "The chosen activities are : \n" << v[0].second << " " << v[0].first << endl;
    for(int i=1; i<n;++i){
        if(v[i].second >= v[k].first){
            cout << v[i].second << " " << v[i].first << endl;
            k = i;
        }
    }
    return 0;
    
}
