#include <algorithm>
#include <bits/stdc++.h>
#include <climits>
#include <vector>
#define pii pair<int,int>
#define s second
#define f first

using namespace std;

/*
int memo[601][101];
int knapsack(int n, int m, vector<pii> a ){
    if (n == 0) 
        return (m / a[n].f) * a[n].s;

    if (memo[n][m] > 0) return memo[n][m];

    if (a[n].f > m) 
        return knapsack(n-1, m, a);
    
    int mx = max(
        a[n].s + knapsack(n, m - a[n].f, a),
        knapsack(n-1,m, a)
    );
    memo[n][m] = mx;
    return mx;


}
*/

int m, n, t, d, p, k;
int main (int argc, char *argv[]){
    int k = 1;
    while (cin >> n >> m && n != 0) {
        vector<pii> a;
        for (int i = 0; i < n; i++) {
            cin >> d >> p;
            a.push_back({d,p});
        }

        int memo[m+1];
        for (int i = 0; i < m+1; i++) memo[i] = 0;


        for (int i = 0; i < m+1; i++)
            for (int j = 0; j < n; j++)
                if (a[j].f <= i)
                    memo[i] = max(memo[i - a[j].f] + a[j].s, memo[i]);
            
        
   
        
        cout << "Instancia " << k++ << endl;
        cout << memo[m] << endl << endl;
        
    }

    


    return 0;
}
