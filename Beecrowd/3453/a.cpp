#include <bits/stdc++.h>
#define ll long long
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define pb push_back

using namespace std;

int main (int argc, char *argv[]){
    cin.tie(0)->sync_with_stdio(0);
    ll n, k, N,aux;
    cin >> n >> k;
    N = (n<<1)+1;
    ll x = 0;
    for (ll i = (n<<1); i > 0; i--) {
        if(k == (i*i)) continue;
        aux = (abs(k-(i*i))); 

        if (aux%N == 0 || aux%(N*N) == 0) {
            x = (i*i);
            //cout << (i*i) << endl;
            break;
        }
    }
    cout << x << endl;
    
    return 0;
}
