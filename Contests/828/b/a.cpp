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
        int n,q;
        cin >> n >> q;

        ll aux, op;
        ll c0 = 0, c1 = 0;
        ll sum0 = 0,sum1 = 0;        

        for (int i = 0; i < n; i++) {
            cin >> aux; 
            if(aux%2 == 0){
                sum0 += aux;
                c0++;
            }
            else{
                sum1 += aux;
                c1++;
            }
        } 
        
        while (q--) {
            cin >> op >> aux;  
            
            if(op){
                if(aux%2 == 0) sum1 += c1 * aux;
                else{
                    sum0 += c1 * aux;
                    sum0 += sum1;
                    sum1 = 0;
                    c0 += c1;
                    c1 = 0;

                }
            }
            else {
                if(aux%2 == 0) sum0 += c0 * aux;
                else{
                    sum1 += c0 * aux;
                    sum1 += sum0;
                    sum0 = 0;
                    c1 += c0;
                    c0 = 0;
                }    
            }
            cout << (ll)sum0 + (ll)sum1 << endl;
        }
    }
    return 0;
}
