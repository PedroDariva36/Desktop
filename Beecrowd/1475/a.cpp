#include <algorithm>
#include <bits/stdc++.h>
#include <climits>
#include <cmath>
#include <vector>

using namespace std;

vector<int> hole;
vector<int> fix;
int a[10000001];
int t, c, aux, best;
/*
int solve(int n, vector<int> &:q
fix ,vector<int> &hole , int &c , int a[]){

    if (a[n] > 0) return a[n];
    int ntop = n;
    for (auto &i : hole) {
        if (i > n) {
            ntop = i; 
            break;
        }
    }
    if (ntop == n)
        return 0;


    int best = c;
    for (int i = n; i <= ntop; i++)
        for (auto f : fix)
            if(f + i < c)
                best = min(f + solve(i+f, fix, hole, c, a),best);
    a[n] = best;
    return best;
}
*/

int solve(int n, int top){
    if (top - 1 >= hole[hole.size()-1]) return 0;

    if (a[n] != -1) return a[n];


    best = min(
        solve(upper_bound(hole.begin(),hole.end(),hole[n] + fix[0]) - hole.begin(), hole[n] + fix[0] + 1) + fix[0],
        solve(upper_bound(hole.begin(),hole.end(),hole[n] + fix[1]) - hole.begin(), hole[n] + fix[1] + 1) + fix[1]
    );

    a[n] = best;
    return best;
}





int main (int argc, char *argv[]){
    while (cin >> t >> c && t != 0) {
        
        fix.clear();
        hole.clear();

        cin >> aux;
        fix.push_back(aux);
        cin >> aux;
        fix.push_back(aux); 
        
        for (int i = 0; i < t; i++) {
            cin >> aux;
            hole.push_back(aux);
        }
        
        for (int i = 0; i < c+1; i++) a[i] = -1;    
        
        /*
        for (int x = c; x >= 0; x--) {
            //cout << x << endl; 
            auto upper = upper_bound(hole.begin(),hole.end(),x);
            if (upper == hole.end()) {
                a[x] = 0;    
                continue;
            }
            ntop = (*upper);
        
            best = a[x];
            for (int i = x; i <= ntop; i++)
                for (auto f : fix)
                    if(f + i < c)
                        best = min(f + a[i+f], best);
            a[x] = best;
        }
        */

        //cout << solve(0, fix, hole, c, a) << endl;
          

        cout << solve(0, 0) << endl; 
        
    }


    return 0;
}
