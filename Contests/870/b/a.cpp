#include <algorithm>
#include <bits/stdc++.h>
#include <vector>
#define ll long long


using namespace std;

int main (int argc, char *argv[]){
    cin.tie(0)->sync_with_stdio(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<long> a(n);
        set<int> s; 

        for (auto &i : a){
            cin >> i; 
        }
         



        int midle = n/2;
        int i = 0;
        int j = n-1;
        
        
        while (i < midle) {
            s.insert(abs(a[i] - a[j]));
            i++;
            j--;
        }
        int g = 0; 
        for (auto &i: s) {
            g = gcd(g,i); 
        }

        cout << g << endl;
    }

    return 0;
}
