#include <bits/stdc++.h>
#include <vector>
#define ll  long long
#define ull unsigned long long
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define pb push_back
using namespace std;



int main (int argc, char *argv[]){
    cin.tie(0)->sync_with_stdio(0);
    int tt;
    cin >> tt;
    while (tt--) {
        int n;
        cin >> n;
        
        vector<char> a(n);
        for(auto &i: a) cin >> i;
        
        vector<char> b;
        char aux = '-';
        for (int i = 0; i < n; i++) {
            if(aux == '-'){
                b.pb(a[i]); 
                aux = a[i];
                continue; 
            }

            if(aux == a[i]) 
                aux = '-';
            
        }

        for(auto &i: b) 
            cout << i;
        cout << endl;


        

         

    }
    return 0;
}
