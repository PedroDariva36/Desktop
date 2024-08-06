#include <bits/stdc++.h>
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
        vector<ll> a; 
        ll aux; 
        for (int i = 0; i < n; i++) {
            cin >> aux;
            if(aux == 0) continue;
            a.pb(aux);
        }       

        bool f = 0;
        ll c = 0;
        ll sum = 0;
        for (int i = 0;i < a.size(); i++) {
            if(a[i] < 0) {
                if(f) 
                    sum +=abs(a[i]);
                else {
                    f = 1;
                    c++;
                    sum +=abs(a[i]);
                }
                continue; 
            }
        
            sum += a[i];
            f = 0;
        }

        cout << sum << " " << c << endl;
        
        





         

    }
    return 0;
}
