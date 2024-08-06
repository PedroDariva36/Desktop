#include <bits/stdc++.h>
#include <cmath>
#include <string>
#define ll long long
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define pb push_back

using namespace std;


bool solve(ll k){
    while (k) {
        ll i = k%10;
        k /= 10; 
        if(i < 5) 
            return false;
    }
    return true;
}



int main (int argc, char *argv[]){
    cin.tie(0)->sync_with_stdio(0);
    int t;
    cin >> t;
    while (t--) {
        ll n;
        cin >> n;
        
        string a,b;
        a = to_string(n>>1);
        b = to_string(((n>>1) + n%2));
        bool f = 0;        
        
        

        if(a.size() != b.size()){
            cout << "NO" << endl;
            continue;
        }

        bool c = 0;
        for (int i = 0;  i < a.size(); i++) {
            int x = a[i] - '0', y = b[i] - '0';

            if(a[i] >= '5' && b[i] >= '5'){
                c = (x + y) > 10;
                continue;
            }
            else {
                if (x+y == 0) {
                    if (c == 1) 
                        c = 0;
                    else {
                        f = 1;
                        break;
                    }
                } 
                else if (y + x <= 8) {
                    if (c == 1) c = 1;
                    else {
                        f = 1;
                        break;
                    }
                }
                else if (x+y == 9){
                    f = 1;
                    break;
                } 
                else if (x+y == 10) c = 0;
                else  c = 1;
            }
        }



         
        cout << (!f?"YES":"NO") << endl;

    }

    return 0;
}
