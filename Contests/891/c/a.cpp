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
        ll n;
        cin >> n;
        ll aux; 
        ll c;
        map<ll,int> m;
        for (ll i = 0; i < (n*n - n)/2; i++) {
            cin >> aux;
            m[-aux]++; 
        } 
        vector<ll> a;
        for (ll i = 1; i < n; i++) {
            aux = -m.begin()->first;
            c = m.begin()->second; 
               
            a.push_back(aux);
            c -= i;

            if(c <= 0) m.erase(m.begin());
            else
                m.begin()->second = c;
        }

        
        for(auto i: a){
            cout << i << " ";
        }
        cout << a[0];
        cout << endl;


        
         

    }
    return 0;
}
