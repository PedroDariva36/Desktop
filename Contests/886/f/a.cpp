#include <algorithm>
#include <bits/stdc++.h>
#include <map>
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
        ll aux; 
        ll ones = 0;
        map<long, long> m;
        vector<long>a(n+1,0); 

        for (int i = 0; i < n; i++) {
            cin >> aux;
            if (aux > n) continue;
            
            m[aux]++;
        }
        for (int i = 1; i <= n; i++) {
            for (int j = i; j <= n; j+=i) {
                a[j]+= m[i];
            } 
        } 
        cout << *max_element(a.begin(),a.end()) << endl;
    }

    return 0;
}
