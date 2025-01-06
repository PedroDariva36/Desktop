#include <bits/stdc++.h>
#include <bitset>
#define ll long long
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define pb push_back

using namespace std;

bitset<64> bs;


int main (int argc, char *argv[]){
    cin.tie(0)->sync_with_stdio(0);
    int t;
    cin >> t;
    while (t--) {
        ll n, k;
        cin >> n >> k;
 
        if(n == 1){
            cout << k << endl;
            continue;
        }

        int p = 1;  
        while ((1ll << p) <= k)
            p++;
        
        bitset<64> x= k;  
        int z = 0;
        for(int i = 0; i < p-1; i++){
            if(x[i]) continue;
            z++; 
        }

    
        if(z > 1){
            cout << (1ll << (p-1)) -1 << " ";
            cout << k - (1ll << (p-1)) + 1 << " ";
            for(int i = 2; i < n; i++)
                cout << 0 << " ";
            cout << endl;
        }

        else{
            cout << k << " ";
            for(int i = 1; i < n; i++)
                cout << 0 << " ";
            cout << endl;
        }



    }

    return 0;
}
