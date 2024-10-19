#include <bits/stdc++.h>
#include <unistd.h>
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
        
        ll k,l,r; 
        
        k = n/3;
        l = k;
        r = k;
        r += n%3;        

        while (r >= l) {
            r--;
            l++;
            while (l >= k) {
                l--;
                k++;
            }
        }




        cout << l << " " << k << " " << r << endl;

        
    

         

    }
    return 0;
}
