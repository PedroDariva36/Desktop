#include <bits/stdc++.h>
#define ll long long
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define pb push_back

using namespace std;

const int N = 1e5+1;
int n;
long t[2*N];
 
 
void build(){
    for(int i = n-1; i > 0; i--) 
        t[i] = t[i<<1] ^ t[i<<1|1];
}
 
void modify(int p, long v){
    for(t[p+=n] = v; p > 1; p >>= 1) t[p >> 1] = t[p] ^ t[p^1]; 
}
 
long query(int l, int r){
   long asw = 0; 
   for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
        if (l&1) asw ^= t[l++];
        if (r&1) asw ^= t[--r];
   }
    return asw; 
}

// q [l,r)


int main (int argc, char *argv[]){
    cin.tie(0)->sync_with_stdio(0);
    int tt;
    cin >> tt;
    while (tt--) {
        int s;
        cin >> s;
        
        n = 1;
        while (n < s) n <<= 1;
        for (int i = n; i < n+s; i++) cin >> t[i];
        for (int i = n+s; i < n+n; i++) t[i] = 0; 
        
        build();


        ll sum = 0;
        for (int i = 0; i < s; i++) {
            long k = query(i, s+1);
            for (int j = i; i < s; i++) {
                if ((k^t[j+n]) > k) {
                    sum++;
                } 
            } 
        }
        for (int i = s-1; i >= 0; i--) {
            long k = query(0, i+1);
            for (int j = i; j >= 0; j--) {
                if ((k^t[j+n]) > k) {
                    sum++;
                } 
            } 
        }




        cout << sum << endl;


    }

    return 0;
}
