#include <algorithm>
#include <bits/stdc++.h>
#include <climits>
#include <iostream>
#include <vector>

using namespace std;

int solve(int n, vector<int> &a, int nt){
    int j = a.size()-1;
    int i = 0;
    int solution = 0;
    while (i <= j) {
        if (nt == 0) return solution;
        
        if (a[i] > n) return INT_MAX - 1;
        
        if (a[j] > n) {
            j--;
            continue;
         }
                
        if (a[i] == n) {
            nt--;
            solution++;
            i++;
            continue;

        }
                
        if (a[j] == n) {
            nt--;
            solution++;
            j--;
            continue;
        }

        if (a[i] + a[j] == n) {
            nt--;
            solution += 2;
            j--;
            i++;
        }
        else if (a[i] + a[j] > n) 
            j--;
        else 
            i++;    
        
    }
    return INT_MAX - 1;
}



double leftover;
int main (int argc, char *argv[]){
    int n, m, l, k, aux ;
        
    while (cin >> n >> m && n != 0) {
        cin >> l >> k;
        int answer[2] = {INT_MAX-1,INT_MAX-1};
        vector<int> a;
        for (int i = 0; i < k; i++) {
            cin >> aux;
            a.push_back(aux);
        }
    
        sort(a.begin(), a.end());
        leftover = n / (l*0.01);
        

        if (leftover == (int)leftover ) answer[0] = solve(n, a, leftover);
        leftover = m / (l*0.01);
        if (leftover == (int)leftover ) answer[1] = solve(m, a, leftover);

        int asw = min(answer[0],answer[1]);
        if (asw == INT_MAX-1) cout << "impossivel" << endl;
        else cout << ++asw << endl;
    }

    return 0;
}
