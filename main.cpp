//
//  main.cpp
//  Truck
//
//  Created by Ragupathi on 21/10/2022.
//

#include <iostream>
#include<vector>
using namespace std;


int dynamic(vector<int> &w, int ind, int w1, int w2, int w3){
   if(ind == 0){
        if(w[0] <= w1){
            return 1;
        }
        else if(w[0] <= w2){
            return 1;
        }
        else if(w[0] <= w3){
            return 1;
        }
        else{
            return 0;
        }
    }
    int take_in_w1 = INT_MIN, take_in_w2 = INT_MIN, take_in_w3 = INT_MIN;
    int notTake_in_any = 0 + dynamic(w, ind-1, w1, w2, w3);
    if(w[ind] <= w1){
        take_in_w1 = 1 + dynamic(w, ind-1, w1-w[ind],w2, w3);
    }
    if(w[ind] <= w2){
        take_in_w2 = 1 + dynamic(w, ind-1, w1,w2-w[ind], w3);
    }
    if(w[ind] <= w3){
        take_in_w2 = 1 + dynamic(w, ind-1, w1,w2, w3-w[ind]);
    }
    
    return max(max(notTake_in_any, take_in_w1), max(take_in_w2, take_in_w3));
    
}


int main() {
    int n, weight, w1, w2, w3;
    cout << "Enter the number of weights : ";
    cin >> n;
    vector<int> w;
    for(int i =0; i<n; ++i){
        cin >> weight;
        w.push_back(weight);
    }
    cout << "Enter the 1st truck's capacity : "; cin >> w1;
    cout << "Enter the 2nd truck's capacity : "; cin >> w2;
    cout << "Enter the 3rd truck's capacity : "; cin >> w3;
    int maximum = dynamic(w, n-1, w1, w2, w3);
    cout << "maximum number of objects used : " << maximum << endl;
    
    
    return 0;
}
