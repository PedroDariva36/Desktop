#include <bits/stdc++.h>
#include <cstdlib>
#include <functional>
#include <iterator>
#include <queue>
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
   
        ll odd = 0;
        ll even = 0;
        ll om = 0;
        ll em = 0;
            
        vector<ll> a;


        ll aux;
        for (int i = 0; i < n; i++) {
            cin >> aux;
            a.pb(aux);
            if(aux%2 == 0){
                even++;
                em = max(em, aux);
            }
            else{
                odd++;
                om = max(om, aux);
            }
        }

         


        if(even == 0 || odd == 0){
            cout << 0 << endl;
            continue;;
        }
    
        sort(all(a));


        if(om < em){
            ll sum = 0;
            for (int i = 0; i < n; i++){
                if (a[i] % 2 == 0 && om >= a[i]) {
                    sum++;
                    om = max(om, om+a[i]);
                } 
                else if (a[i] % 2 == 0 && om < a[i]) {
                    sum +=2;
                    om = om+em;
                }
            }
            cout << sum << endl;
        }
        else{
            cout << even << endl;;
        }
        
            


        

         

    }
    return 0;
}
