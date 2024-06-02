#include <bits/stdc++.h>
#include <ios>
#include <vector>
#define ll long long
using namespace std;



int main (int argc, char *argv[]){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int t;
    cin >> t;
    while (t--) {
        int n;
        ll aux;
        cin >> n;
        map<long,long> m;
        
        for(int i = 0; i < n; i++){
            cin >> aux;
            m[aux]++;
        }
        
        vector<long> a;
        for (auto &i : m) a.push_back(i.first); 
    
        //for (auto i: a) cout << i << endl; 

        int sum = 0;
        int p = 0;
        for (int i = 0; i < a.size(); i++) {
            while (a[p] - a[i] < n && p < a.size()) p++;
            sum = max(sum, (p - i));
        }
        
        cout << sum << endl;




    }
    return 0;
}
