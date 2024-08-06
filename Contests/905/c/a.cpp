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
        ll k;
        cin >> n >> k;
        vector<ll> a;
        ll aux; 

        bool f = 0;
        ll prod = 1; 
        for (int i = 0; i<n; i++) {
            cin >> aux;
            prod *= aux;
            if(aux%k == 0 || prod%k == 0) f = true; 
            a.pb(aux%k);
        }
         
        if(f){
            cout << 0 << endl;
            continue;
        }
            
        ll sum = k;       

        sort(rall(a));
        sum = min(abs(a[0]-k)%k,sum);   
       
        prod = 1;
        ll c = 0;
        for (int i = 0; i < n-1; i++) {
            prod *= a[i];
        } 
        
        while (prod * a.back() % k != 0) {
            c++;
            a.back()++;
        }
            
        //if(c != 0)
            sum = min(sum,c);

        cout << sum << endl; 


    }
    return 0;
}
