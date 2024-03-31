#include <bits/stdc++.h>
#include <cmath>
#include <numeric>
#include <vector>
#define ll long long

using namespace std;
    

int solve(vector<int> &a, int k, int n){
    int d = 0;
    for(int i = 0; i+k < n; i++)
        d = gcd(d, abs(a[i+k] - a[i]));
    return (d != 1); 
}



int main (int argc, char *argv[]){
    cin.tie(0)->sync_with_stdio(0);
    
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        
        vector<int> a(n);
        ll sum = 0;
        
        for(int i = 0; i < n; i++)
            cin >> a[i];
            
        for(int k = 1; k <= sqrt(n); k++){
            if(n%k == 0){
                sum += solve(a, k, n); 
                if(n/k != k){
                    sum += solve(a, n/k, n);
                }
            }
        }
        cout << sum << endl;
    }

    

    return 0;
}
