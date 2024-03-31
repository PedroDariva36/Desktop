#include <bits/stdc++.h>
#include <ios>
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
        set<long> s;
        
        for(int i = 0; i < n; i++){
            cin >> aux;
            m[aux]++;
        }
        int n1 = 1;
        long last = 0;
        for(auto i : m){
            long k = i.first - last;

            if(k == i.first){
                last = i.first;
                continue;
            }
            last = i.first;
            
            if(k == 1){
                n1++;
                continue;
            }
        
            if(k < n)
                s.insert(k);
        }       

        
        cout << max(n1 , (int)s.size()+1) << endl;





    }
    return 0;
}
