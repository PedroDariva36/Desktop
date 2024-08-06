#include <algorithm>
#include <bits/stdc++.h>
#include <iomanip>
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
        long double d, h;
        cin >> n >> d >> h;
        long double A = atan(h/(d/2));
         
        vector<ll> a(n); 
        for (auto &i : a) {
            cin >> i;
        }

        reverse(all(a)); 

        long double sum = 0; 
        sum += (h*d)/2;
        
        for (int i = 1; i < n; i++) {
            long double dif = a[i-1] - a[i];
            if(dif >= h){
                sum += (h*d)/2;
                continue;
            }


            long double aux = ((d + ((h-dif)/tan(A))*2) /2) * (dif);
            sum += aux;
        }

        cout << setprecision(8) << sum << endl;




        
         

    }
    return 0;
}
