#include <bits/stdc++.h>
#include <unistd.h>
#define ll  long long
#define ull unsigned long long
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define pb push_back
using namespace std;


const int N = 2*1e5;
int n;
ll t[2*N];
 

void build(){
    for(int i = n-1; i > 0; i--){
        t[i] = t[i<<1] & t[i<<1|1];
    }
}

ll query(int l, int r){
    ll asw = (1LL << 30)-1; 
    for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
        if (l&1) asw = asw & t[l++];
        if (r&1) asw = asw & t[--r];
    }
    return asw; 
}



int main (int argc, char *argv[]){
    cin.tie(0)->sync_with_stdio(0);
    int tt;
    cin >> tt;
    while (tt--) {
        int s;
        cin >> s;
        
        n = 1;
        while (n < s) n <<= 1;
        for (int i = n; i < n+s;i++) cin >> t[i];
        build();
    
        int q;
        cin >> q;
        while(q--){
            ll l, k;
            cin >> l >> k;
            l--; 
            if(query(l,l+1) < k){
                cout << -1 << " ";
                continue;
            }


            ll aux = l;    
            ll r = s+1;
            ll asw = l;
            while(l <= r){
                ll mid = (l + r)/2;
                if(query(aux, mid+1) >= k){
                    asw = max(asw, mid);
                    l = mid+1;
                }
                else 
                    r  = mid-1;
            }

            cout << asw+1 << " ";
        }   
        cout << endl; 


    }
    return 0;
}
