#include <bits/stdc++.h>
#define ll long long
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define pb push_back

using namespace std;


int main (int argc, char *argv[]){
    cin.tie(0)->sync_with_stdio(0);
    int t;
    cin >> t;
    while (t--){
        int n, m, q, aux;
        cin >> n >> m >> q;
        
        vector<ll> k(m+1);
        vector<ll> b(m+1);
    
        for (int i = 1; i <= m; i++) cin >> k[i]; 
        for (int i = 1; i <= m; i++) cin >> b[i]; 

        
        while (q--) {
            cin >> aux;
            int l = 0;
            int r = m; 

            while(l <= r){
                int mid = (l+r)>>1;
                if(k[mid] > aux)
                    r = mid-1;
                else
                    l = mid+1;
            }            

            if (k[r] == aux){
                cout << b[r] << " ";
                continue;
            }

            ll ans = b[r] + (aux-k[r])*(b[r+1]-b[r])/(k[r+1]-k[r]);
            cout << ans << " ";

        }


        cout << endl;

    }

    return 0;
}
